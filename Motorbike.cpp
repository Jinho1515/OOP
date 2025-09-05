#include "Vehicle.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int raw = this->secondsSinceEntry();
    int reduced = static_cast<int>(raw * 0.85); // 15% reduction
    return reduced;
}
