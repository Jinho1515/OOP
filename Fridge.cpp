#include "Fridge.h"

Fridge::Fridge()
    : Appliance(), volume(0.0) {
}

Fridge::Fridge(int powerRating, double volume)
    : Appliance(powerRating), volume(volume) {
}

void Fridge::setVolume(double v) {
    volume = v;
}

double Fridge::getVolume() const {
    return volume;
}

// power consumption = power rating * 24 * (volume / 100)
double Fridge::getPowerConsumption() const {
    return static_cast<double>(get_powerRating()) * 24.0 * (volume / 100.0);
}
