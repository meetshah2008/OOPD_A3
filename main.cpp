#include "StationLibrary.h"
#include <iostream>
#include <limits> // For clearing input buffer

void displayMenu() {
    std::cout << "\n--- Train Station Management ---\n";
    std::cout << "1. Add a Line\n";
    std::cout << "2. Add a Platform to a Line\n";
    std::cout << "3. Book a Train\n";
    std::cout << "4. Print Line Details\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Station station;

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        // Clear input buffer to avoid input issues
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            // Add a Line
            std::string lineID;
            std::cout << "Enter Line ID: ";
            std::cin >> lineID;

            Line<std::string> newLine(lineID);
            station.addLine(newLine);
            std::cout << "Line " << lineID << " added successfully.\n";
            break;
        }

        case 2: {
            // Add a Platform to a Line
            std::string lineID;
            int platformNumber;
            std::cout << "Enter Line ID: ";
            std::cin >> lineID;

            std::cout << "Enter Platform Number: ";
            std::cin >> platformNumber;

            bool lineFound = false;
            for (auto& line : station.getLines()) {
                if (line.getLineID() == lineID) {
                    Platform platform(platformNumber);
                    line.addPlatform(platform);
                    std::cout << "Platform " << platformNumber << " added to Line " << lineID << ".\n";
                    lineFound = true;
                    break;
                }
            }

            if (!lineFound) {
                std::cerr << "Error: Line " << lineID << " not found.\n";
            }
            break;
        }

        case 3: {
            // Book a Train
            std::string lineID;
            int platformNumber, trainTime;
            bool isThrough;

            std::cout << "Enter Line ID: ";
            std::cin >> lineID;

            std::cout << "Enter Platform Number: ";
            std::cin >> platformNumber;

            std::cout << "Enter Train Time (HHMM): ";
            std::cin >> trainTime;

            std::cout << "Is it a Through Train? (1 for Yes, 0 for No): ";
            std::cin >> isThrough;

            bool trainBooked = false;

            for (auto& line : station.getLines()) {
                if (line.getLineID() == lineID) {
                    for (auto& platform : line.getPlatforms()) {
                        if (platform.getPlatformNumber() == platformNumber) {
                            try {
                                if (isThrough) {
                                    platform.addThroughTrainTiming(trainTime);
                                } else {
                                    platform.addStoppageTiming(trainTime);
                                }
                                std::cout << "Train booked successfully at platform "
                                          << platformNumber << " at time "
                                          << trainTime << " ("
                                          << (isThrough ? "Through Train" : "Stoppage Train") << ")\n";
                                trainBooked = true;
                            } catch (const InvalidInputException& e) {
                                std::cerr << "Error: Time gap between trains is insufficient!\n";
                            }
                            break;
                        }
                    }
                }
                if (trainBooked) break;
            }

            if (!trainBooked) {
                std::cerr << "Error: Unable to book train. Ensure the platform and line exist.\n";
            }
            break;
        }

        case 4: {
            // Print Line Details
            for (const auto& line : station.getLines()) {
                line.printLineDetails();
            }
            break;
        }

        case 5: {
            // Exit
            std::cout << "Exiting the program. Goodbye!\n";
            return 0;
        }

        default:
            std::cerr << "Invalid choice. Please select a valid option.\n";
        }
    }
}
