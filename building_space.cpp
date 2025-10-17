#include "building_space.h"
#include "building.h"
#include <algorithm>
building_space::building_space(int total_space) {
    this->total_space = total_space;
    space = new building*[total_space];
    occupied = 0;
}

building** building_space::get_space() {
    return space;
}

bool building_space::popularise(building* type) {
    if (occupied < total_space)
        {
            space[occupied] = type;
            occupied++;
            return true;
        } else {
            return false;
        }
        
}

