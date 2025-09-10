#pragma once
#include "Appliance.h"

class Fridge : public Appliance {
private:
    double volume; // in litres

public:
    Fridge();
    Fridge(int powerRating, double volume);

    void   setVolume(double volume);
    double getVolume() const;

    // Override the virtual method from Appliance
    double getPowerConsumption() const override;
};
