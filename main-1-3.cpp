#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot lot(10);

    int needCar = 5, needBus = 3, needBike = 2;
    int nextID = 1;

    while (lot.getCount() < 10) {
        int type;
        std::cin >> type; // 1=Car, 2=Bus, 3=Motorbike

        if (type == 1) {
            if (needCar > 0) {
                lot.parkVehicle(new Car(nextID++));
                needCar--;
            } else {
                std::cout << "No more Cars needed\n";
            }
        } else if (type == 2) {
            if (needBus > 0) {
                lot.parkVehicle(new Bus(nextID++));
                needBus--;
            } else {
                std::cout << "No more Buses needed\n";
            }
        } else if (type == 3) {
            if (needBike > 0) {
                lot.parkVehicle(new Motorbike(nextID++));
                needBike--;
            } else {
                std::cout << "No more Motorbikes needed\n";
            }
        } else {
            std::cout << "Invalid type\n";
        }
    }

    int over = lot.countOverstayingVehicles(15);
    std::cout << over << std::endl;

    return 0;
}
