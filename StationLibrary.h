#ifndef STATIONLIBRARY_H
#define STATIONLIBRARY_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

// Custom exception class
class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override;
};

// Platform class
class Platform {
private:
    int platformNumber;
    std::vector<int> stoppageTimings;
    std::vector<int> throughTrainTimings;

public:
    Platform(int number);

    int getPlatformNumber() const;

    void addStoppageTiming(int time);

    void addThroughTrainTiming(int time);

    void printTimings() const;
};

// Line class (templated)
template<typename T>
class Line {
private:
    T lineID;
    std::vector<Platform> platforms;

public:
    Line(T id);

    T getLineID() const;

    void addPlatform(const Platform& platform);

    std::vector<Platform>& getPlatforms();

    void printLineDetails() const;
};

// Station class
class Station {
private:
    std::vector<Line<std::string>> lines;

public:
    void addLine(const Line<std::string>& line);

    std::vector<Line<std::string>>& getLines();
};

#endif // STATIONLIBRARY_H
