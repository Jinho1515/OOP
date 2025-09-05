#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int raw = this->secondsSinceEntry();
    return static_cast<int>(raw * 0.90);
}
