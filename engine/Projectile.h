#pragma once
#include "Vec2.h"
#include <vector>
#include <string>

class EnemyUnit;

class Projectile {
public:
    Vec2  pos;
    float speed = 10.f;
    float hitRadius = 0.3f;
    int   damage = 4;
    std::string damageType = "physical";
    int   targetIndex = -1; // index into enemies vector
    bool  alive = true;

    void update(std::vector<EnemyUnit>& enemies, float dt);
};
