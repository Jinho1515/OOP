#pragma once
#include <string>
#include "Vec2.h"
#include "Path.h"

// EnemyUnit is a *runtime unit* that moves on the path and has its own HP.
// It is *initialised* from kai enemy subclasses (goblin/ogre/skeleton).
class EnemyUnit {
public:
    // copied from your enemy type at spawn time
    int   base_damage = 1;
    int   max_hp      = 10;
    std::string res   = "none"; // resistance type string ("physical","magic","none")

    // dynamic state
    int   hp          = 10;
    float speed       = 0.2f; // units per second
    bool  dead        = false;
    bool  escaped     = false;

    // path-follow state
    int   seg   = 0;    // between nodes[seg] -> nodes[seg+1]
    float t     = 0.f;  // 0..1 along current segment
    Vec2  pos;          // cached position

    void spawn(const Path& p);
    void update(const Path& p, float dt);
    void takeDamage(int dmg, const std::string& dam_type);
    float progress() const { return float(seg) + t; } // larger = closer to end

    int  bounty     = 10;  // money awarded when this unit dies
    bool bountyPaid = false; // guard so we pay exactly once

};
