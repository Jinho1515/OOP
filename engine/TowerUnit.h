#pragma once
#include <string>
#include <vector>
#include <limits>
#include "Vec2.h"

class EnemyUnit;
class Projectile;
class building; // from code

// TowerUnit wraps building-derived objects (ballista mage or some shit)
// and adds runtime cooldown/position.
class TowerUnit {
public:
    building* backing = nullptr; // non-owning pointer to building object
    std::string name  = "Tower";
    Vec2  pos;
    float range     = 5.f;
    float fireRate  = 1.0f; // shots/sec
    int   damage    = 5;
    std::string damageType = "physical";
    float cooldown  = 0.f;

    int  acquire(const std::vector<EnemyUnit>& enemies) const;
    void update(float dt, std::vector<EnemyUnit>& enemies, std::vector<Projectile>& projectiles);
};
