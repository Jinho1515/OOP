#include <iostream>
#include <ctime>
#include "vehicle.h"

class Bus : public Vehicle {
public:
    Bus(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int raw = this->secondsSinceEntry();
        int reduced = static_cast<int>(raw * 0.75); // 25% reduction
        return reduced;
    }
};