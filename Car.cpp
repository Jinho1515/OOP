#include "Vehicle.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int raw = this->secondsSinceEntry();
    int reduced = static_cast<int>(raw * 0.90); // 10% reduction
    return reduced;
}
