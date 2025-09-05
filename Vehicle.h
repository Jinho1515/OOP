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


class Car : public Vehicle {
public:
    explicit Car(int id);
    int getParkingDuration() const override;
};

class Bus : public Vehicle {
public:
    explicit Bus(int id);
    int getParkingDuration() const override;
};

class Motorbike : public Vehicle {
public:
    explicit Motorbike(int id);
    int getParkingDuration() const override;
};

#endif // VEHICLE_H
