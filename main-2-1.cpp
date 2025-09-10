#include <iostream>
#include <iomanip>
#include "Fridge.h"

int main() {
    Fridge f1;                   // default: power=0, volume=0
    Fridge f2(120, 350.0);       // 120 W, 350 L

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "f1: power=" << f1.get_powerRating()
              << "W, volume=" << f1.getVolume()
              << "L, consumption=" << f1.getPowerConsumption() << "\n";

    std::cout << "f2: power=" << f2.get_powerRating()
              << "W, volume=" << f2.getVolume()
              << "L, consumption=" << f2.getPowerConsumption() << "\n";

    // Change f1 values and recompute
    f1.set_powerRating(90);
    f1.setVolume(250.0);
    std::cout << "f1 updated: power=" << f1.get_powerRating()
              << "W, volume=" << f1.getVolume()
              << "L, consumption=" << f1.getPowerConsumption() << "\n";

    return 0;
}
