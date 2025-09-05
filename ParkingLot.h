#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"

class ParkingLot {
private:
    Vehicle** vehicles; // dynamic array of Vehicle*
    int capacity;
    int count;

public:
    explicit ParkingLot(int max);
    ~ParkingLot();

    int getCount() const;

    void parkVehicle(Vehicle* v);  // prints "The lot is full" if full
    void unparkVehicle(int id);    // prints "Vehicle not in the lot" if absent

    // NEW (Q1-3): number of vehicles with duration > maxParkingDuration (seconds)
    int countOverstayingVehicles(int maxParkingDuration) const;
};

#endif // PARKINGLOT_H
