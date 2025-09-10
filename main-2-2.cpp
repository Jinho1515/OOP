#include <iostream>
#include <iomanip>
#include "TV.h"

int main() {
    TV t1;                // default: 0 W, 0"
    TV t2(80, 55.0);      // 80 W, 55"

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "t1: power=" << t1.get_powerRating()
              << "W, size=" << t1.getScreenSize()
              << "\", consumption=" << t1.getPowerConsumption() << "\n";

    std::cout << "t2: power=" << t2.get_powerRating()
              << "W, size=" << t2.getScreenSize()
              << "\", consumption=" << t2.getPowerConsumption() << "\n";

    // Update t1 and recompute
    t1.set_powerRating(65);
    t1.setScreenSize(43.0);
    std::cout << "t1 updated: power=" << t1.get_powerRating()
              << "W, size=" << t1.getScreenSize()
              << "\", consumption=" << t1.getPowerConsumption() << "\n";

    return 0;
}
