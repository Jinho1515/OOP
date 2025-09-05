#include <iostream>
#include <ctime>
#include "vehicle.h"

class Motorbike : public Vehicle {
public:
    Motorbike(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int raw = this->secondsSinceEntry();
        int reduced = static_cast<int>(raw * 0.85); // 15% reduction
        return reduced;
    }
};