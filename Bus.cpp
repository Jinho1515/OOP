#include "Vehicle.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int raw = this->secondsSinceEntry();
    int reduced = static_cast<int>(raw * 0.75); // 25% reduction
    return reduced;
}
