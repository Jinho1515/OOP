#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot lot(10);

    // Fill the lot using parkVehicle()
    while (lot.getCount() < 10) {
        int type, id;
        std::cin >> type >> id; // e.g. "1 101" (Car 101), "2 202" (Bus 202), "3 303" (Motorbike 303)

        Vehicle* v = nullptr;
        if (type == 1)      v = new Car(id);
        else if (type == 2) v = new Bus(id);
        else if (type == 3) v = new Motorbike(id);
        else                v = new Car(id); // default to Car

        lot.parkVehicle(v);
    }

    // Ask which ID to unpark
    int removeID;
    std::cin >> removeID;
    lot.unparkVehicle(removeID);

    return 0;
}
