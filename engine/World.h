#pragma once
#include <vector>
#include <string>
#include "Path.h"
#include "EnemyUnit.h"
#include "TowerUnit.h"
#include "Projectile.h"
#include "BuildSlots.h"

class player;
class building_space;
class building;

class World {
public:
    Path path;
    BuildSlots slots;
    std::vector<EnemyUnit>   enemies;
    std::vector<TowerUnit>   towers;      // derived from placed buildings
    std::vector<Projectile>  projectiles;
    player* playerRef = nullptr; // reduces lives on escape

    void update(float dt);
    void addLives(int delta);  // negative reduces lives
    
    float timeScale = 1.0f;     // 1.0 = normal, 0.5 = slower, 2.0 = faster
    void setTimeScale(float s); // clamp and set
    
};
