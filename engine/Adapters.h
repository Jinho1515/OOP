#pragma once
#include <string>
#include <typeinfo>
#include "EnemyUnit.h"
#include "goblin.h"
#include "ogre.h"
#include "skeleton.h"
#include "ballista.h"
#include "mage_tower.h"
#include "farm.h"
#include "building.h"

// Make EnemyUnit stats from kai enemy type name.
inline EnemyUnit makeEnemyUnitFromType(const std::string& type, float speed){
    EnemyUnit u;
    if (type == "goblin"){
        goblin g(1);
        u.base_damage = g.get_damage();
        u.max_hp      = g.get_health();
        u.res         = g.get_res();
        u.bounty      = 10;  
    } else if (type == "ogre"){
        ogre o(1);
        u.base_damage = o.get_damage();
        u.max_hp      = o.get_health();
        u.res         = o.get_res();
        u.bounty      = 25;  
    } else { 
        skeleton s(1);
        u.base_damage = s.get_damage();
        u.max_hp      = s.get_health();
        u.res         = s.get_res();
        u.bounty      = 12;   // money that when they dies
    }
    u.speed = speed;
    return u;
}

// Make a building by type id (1 ballista, 2 mage, 3 farm).
// Caller owns the returned pointer.
inline building* createBuildingByType(int type, int locationIndex){
    if (type == 1) return new ballista(locationIndex);
    if (type == 2) return new mage_tower(locationIndex);
    return new farm(locationIndex); // non-attacking, income building
}

// Copy stats from building to TowerUnit (range, fire rate, damage, damage type).
inline void syncTowerUnitFromBuilding(TowerUnit& tu, building* b){
    tu.backing = b;
    tu.name = typeid(*b).name(); // simple runtime name
    // Use mr bright building getters (assumed available in building.h/.cpp)
    tu.range     = (float)b->get_range();
    tu.fireRate  = b->get_fire_rate();
    tu.damage    = (int)b->get_damage();
    tu.damageType= b->get_damageType();
}
