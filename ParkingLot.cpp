#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int max) {
    this->capacity = max;
    this->count = 0;
    this->vehicles = new Vehicle*[this->capacity](); // zero-init to nullptr
}

ParkingLot::~ParkingLot() {
    // Ownership not specified by the spec, so we DO NOT delete vehicles[i].
    delete[] this->vehicles;
}

int ParkingLot::getCount() const {
    return this->count;
}

void ParkingLot::parkVehicle(Vehicle* v) {
    if (this->count >= this->capacity) {
        std::cout << "The lot is full" << std::endl;
        return;
    }
    this->vehicles[this->count] = v;
    this->count += 1;
}

void ParkingLot::unparkVehicle(int id) {
    for (int i = 0; i < this->count; ++i) {
        if (this->vehicles[i]->getID() == id) {
            // compact the array after removing slot i
            for (int j = i; j < this->count - 1; ++j) {
                this->vehicles[j] = this->vehicles[j + 1];
            }
            this->vehicles[this->count - 1] = nullptr;
            this->count -= 1;
            return;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
}
