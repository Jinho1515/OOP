#pragma once
#include <vector>
#include "Vec2.h"

// Developer-chosen buildable positions on the map.
struct BuildSlots {
    std::vector<Vec2> positions; // slot i -> world coordinate
};
