#include <iostream>
#include <iomanip>
#include "House.h"
#include "Fridge.h"
#include "TV.h"

int main() {
    House h(3);

    h.addAppliance(new Fridge(120, 350.0)); // 120 W, 350 L
    h.addAppliance(new TV(80, 55.0));       // 80 W, 55"
    h.addAppliance(new TV(65, 43.0));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total daily power consumption: "
              << h.getTotalPowerConsumption() << "\n";

    return 0;
}
