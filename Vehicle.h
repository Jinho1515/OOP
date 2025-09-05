#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>

class Vehicle {
private:
    std::time_t timeOfEntry;
    int ID;

protected:
    int secondsSinceEntry() const;

public:
    explicit Vehicle(int id);
    virtual ~Vehicle();
    int getID() const;
    virtual int getParkingDuration() const = 0;
};

#endif // VEHICLE_H
