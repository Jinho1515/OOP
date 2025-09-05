#include <iostream>
#include <ctime>
#include "vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int n;
    std::cout << "Enter number of vehicles: ";
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    Vehicle** lot = new Vehicle*[n];

    for (int i = 0; i < n; i++) {
        int type;
        int id;

        std::cout << "Vehicle " << (i + 1) << " type (1=Car, 2=Bus, 3=Motorbike): ";
        std::cin >> type;

        std::cout << "Enter ID: ";
        std::cin >> id;

        if (type == 1) {
            lot[i] = new Car(id);
        } else if (type == 2) {
            lot[i] = new Bus(id);
        } else if (type == 3) {
            lot[i] = new Motorbike(id);
        } else {
            std::cout << "Invalid type. Defaulting to Car.\n";
            lot[i] = new Car(id);
        }
    }

    // Print parking duration (in seconds) for each vehicle
    for (int i = 0; i < n; i++) {
        std::cout << "Vehicle " << lot[i]->getID()
                  << " duration (s): " << lot[i]->getParkingDuration()
                  << "\n";
    }

    for (int i = 0; i < n; i++) {
        delete lot[i];
    }
    delete[] lot;

    return 0;
}