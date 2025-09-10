#include "House.h"
#include <cstddef>

House::House() : appliances(nullptr), capacity(0), count(0) {}

House::House(int numAppliances)
    : capacity(numAppliances), count(0) {
    appliances = (capacity > 0) ? new Appliance*[capacity] : nullptr;
    for (int i = 0; i < capacity; ++i) appliances[i] = nullptr;
}

House::~House() {
    if (appliances) {
        for (int i = 0; i < count; ++i) {
            delete appliances[i];        // delete owned appliance
        }
        delete[] appliances;             // delete pointer array
    }
}

bool House::addAppliance(Appliance* appliance) {
    if (!appliance || count >= capacity) return false;
    appliances[count++] = appliance;     // take ownership
    return true;
}

double House::getTotalPowerConsumption() const {
    double total = 0.0;
    for (int i = 0; i < count; ++i) {
        total += appliances[i]->getPowerConsumption(); // virtual dispatch
    }
    return total;
}
