#include "TowerUnit.h"
#include "EnemyUnit.h"
#include "Projectile.h"
#include "Vec2.h"

int TowerUnit::acquire(const std::vector<EnemyUnit>& enemies) const {
    float bestProg = -std::numeric_limits<float>::infinity(); //bestProg tracks the largest progress value seen so far 
    int best = -1;
    float r2 = range * range; // tower shoots this range
    for (int i=0;i<(int)enemies.size();++i){
        if (enemies[i].dead || enemies[i].escaped) continue;
        if (dist2(pos, enemies[i].pos) <= r2){ //check range
            float prog = enemies[i].progress();
            if (prog > bestProg){ bestProg = prog; best = i; }
        }
    }
    return best;
}

void TowerUnit::update(float dt, std::vector<EnemyUnit>& enemies, std::vector<Projectile>& projectiles){
    if (cooldown > 0) cooldown -= dt;
    if (cooldown > 0) return;
    int idx = acquire(enemies);
    if (idx == -1) return;
    Projectile p;
    p.pos = pos;
    p.damage = damage;
    p.damageType = damageType;
    p.targetIndex = idx;
    projectiles.push_back(p);
    cooldown = (fireRate > 0 ? 1.f / fireRate : 0.5f);
}
// tbh i dont fukin know for ts part bc gpt did it, at least it works pre good THE GOAT