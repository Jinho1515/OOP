#pragma once
#include "Appliance.h"

class TV : public Appliance {
private:
    double screenSize; // inches

public:
    TV();
    TV(int powerRating, double screenSize);

    void   setScreenSize(double screenSize);
    double getScreenSize() const;

    // power consumption = power rating * (screen size / 10)
    double getPowerConsumption() const override;
};
