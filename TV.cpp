#include "TV.h"

TV::TV() : Appliance(), screenSize(0.0) {}

TV::TV(int powerRating, double screen)
    : Appliance(powerRating), screenSize(screen) {}

void TV::setScreenSize(double s) { screenSize = s; }

double TV::getScreenSize() const { return screenSize; }

double TV::getPowerConsumption() const {
    return static_cast<double>(get_powerRating()) * (screenSize / 10.0);
}
