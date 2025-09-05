#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"

class ParkingLot {
private:
    Vehicle** vehicles; // dynamic array of Vehicle*  (name required by spec)
    int capacity;       // max spaces
    int count;          // current number of vehicles

public:
    explicit ParkingLot(int max);
    ~ParkingLot();

    int getCount() const;

    // Spec: print messages on failure conditions
    void parkVehicle(Vehicle* v); // prints "The lot is full" if full
    void unparkVehicle(int id);   // prints "Vehicle not in the lot" if ID absent
};

#endif // PARKINGLOT_H
