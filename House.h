#pragma once
#include "Appliance.h"

class House {
private:
    Appliance** appliances;  // array of pointers
    int capacity;            // max slots
    int count;               // used slots

public:
    House();                             // empty house
    explicit House(int numAppliances);   // allocate slots
    ~House();                            // deletes owned appliances

    // No copying (ownership semantics kept simple)
    House(const House&) = delete;
    House& operator=(const House&) = delete;

    // Adding transfers ownership only if it returns true.
    bool addAppliance(Appliance* appliance);

    // Sum of all appliances' consumptions
    double getTotalPowerConsumption() const;
};
