#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"


int main() {
    int n;
    std::cin >> n;
    if (n <= 0) return 0;

    Vehicle** lot = new Vehicle*[n](); // zero-init pointers

    for (int i = 0; i < n; i++) {
        int type, id;
        std::cin >> type >> id;

        if (type == 1)      lot[i] = new Car(id);
        else if (type == 2) lot[i] = new Bus(id);
        else if (type == 3) lot[i] = new Motorbike(id);
        else                lot[i] = new Car(id); // default
    }

    for (int i = 0; i < n; i++) {
        std::cout << lot[i]->getParkingDuration() << "\n";
    }

    for (int i = 0; i < n; i++) delete lot[i];
    delete[] lot;

    return 0;
}
