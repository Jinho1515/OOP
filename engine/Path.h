#pragma once
#include <vector>
#include "Vec2.h"

class Path {
public:
    std::vector<Vec2> nodes;
    bool valid() const { return nodes.size() >= 2; }
};
