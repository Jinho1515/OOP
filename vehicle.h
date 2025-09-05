#include <iostream>
#include <ctime>
#pragma once

class Vehicle {
private:
    std::time_t timeOfEntry;
    int ID;

protected:
    int secondsSinceEntry() const {
        std::time_t now = std::time(nullptr);
        return static_cast<int>(std::difftime(now, this->timeOfEntry));
    }

public:
    Vehicle(int id) {
        this->ID = id;
        this->timeOfEntry = std::time(nullptr);
    }

    virtual ~Vehicle() {}

    int getID() const {
        return this->ID;
    }

    virtual int getParkingDuration() const = 0; // in seconds (after reduction)
};