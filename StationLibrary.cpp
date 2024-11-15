#include "StationLibrary.h"

// Implementation of InvalidInputException
const char* InvalidInputException::what() const noexcept {
    return "Invalid input!";
}

// Implementation of Platform class
Platform::Platform(int number) : platformNumber(number) {}

int Platform::getPlatformNumber() const {
    return platformNumber;
}

void Platform::addStoppageTiming(int time) {
    if (!stoppageTimings.empty() && time <= stoppageTimings.back()) {
        throw InvalidInputException();
    }
    stoppageTimings.push_back(time);
}

void Platform::addThroughTrainTiming(int time) {
    if (!throughTrainTimings.empty() && time <= throughTrainTimings.back()) {
        throw InvalidInputException();
    }
    throughTrainTimings.push_back(time);
}

void Platform::printTimings() const {
    std::cout << "Platform " << platformNumber << " Timings:\n";
    std::cout << "Stoppage Times: ";
    for (int time : stoppageTimings) {
        std::cout << time << " ";
    }
    std::cout << "\nThrough Train Times: ";
    for (int time : throughTrainTimings) {
        std::cout << time << " ";
    }
    std::cout << std::endl;
}

// Implementation of Line class (templated)
template<typename T>
Line<T>::Line(T id) : lineID(id) {}

template<typename T>
T Line<T>::getLineID() const {
    return lineID;
}

template<typename T>
void Line<T>::addPlatform(const Platform& platform) {
    platforms.push_back(platform);
}

template<typename T>
std::vector<Platform>& Line<T>::getPlatforms() {
    return platforms;
}

template<typename T>
void Line<T>::printLineDetails() const {
    std::cout << "Line " << lineID << ":\n";
    for (const auto& platform : platforms) {
        platform.printTimings();
    }
}

// Explicit instantiation of the Line class for std::string
template class Line<std::string>;

// Implementation of Station class
void Station::addLine(const Line<std::string>& line) {
    lines.push_back(line);
}

std::vector<Line<std::string>>& Station::getLines() {
    return lines;
}
