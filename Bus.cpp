#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int raw = this->secondsSinceEntry();
    return static_cast<int>(raw * 0.75);
}
