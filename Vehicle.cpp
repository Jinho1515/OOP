#include "Vehicle.h"
#include <ctime>

Vehicle::Vehicle(int id) {
    this->ID = id;
    this->timeOfEntry = std::time(nullptr);
}

Vehicle::~Vehicle() {}

int Vehicle::getID() const {
    return this->ID;
}

int Vehicle::secondsSinceEntry() const {
    std::time_t now = std::time(nullptr);
    double diff = std::difftime(now, this->timeOfEntry);
    return static_cast<int>(diff);
}
