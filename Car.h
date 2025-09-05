#include <iostream>
#include <ctime>
#include "vehicle.h"

class Car : public Vehicle {
public:
    Car(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int raw = this->secondsSinceEntry();
        int reduced = static_cast<int>(raw * 0.90); // 10% reduction
        return reduced;
    }
};
