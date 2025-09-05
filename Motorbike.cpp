#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int raw = this->secondsSinceEntry();
    return static_cast<int>(raw * 0.85);
}
