#include <iostream>
#include "Appliance.h"

int main() {
    Appliance a1;           // default: 0 W, off
    Appliance a2(1500);     // 1500 W, off

    std::cout << "a1: power=" << a1.get_powerRating()
              << "W, isOn=" << (a1.get_isOn() ? "true" : "false")
              << ", consumption=" << a1.getPowerConsumption() << "\n";

    std::cout << "a2: power=" << a2.get_powerRating()
              << "W, isOn=" << (a2.get_isOn() ? "true" : "false")
              << ", consumption=" << a2.getPowerConsumption() << "\n";

    a2.turnOn();
    std::cout << "a2 after turnOn -> isOn=" << (a2.get_isOn() ? "true" : "false") << "\n";
    a2.turnOff();
    std::cout << "a2 after turnOff -> isOn=" << (a2.get_isOn() ? "true" : "false") << "\n";

    a1.set_powerRating(800);
    a1.set_isOn(true);
    std::cout << "a1 updated: power=" << a1.get_powerRating()
              << "W, isOn=" << (a1.get_isOn() ? "true" : "false") << "\n";

    return 0;
}
