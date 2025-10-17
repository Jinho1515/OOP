#include "Projectile.h"
#include "EnemyUnit.h"
#include <cmath>

void Projectile::update(std::vector<EnemyUnit>& enemies, float dt){
    if (!alive) return;
    if (targetIndex < 0 || targetIndex >= (int)enemies.size()
        || enemies[targetIndex].dead || enemies[targetIndex].escaped){
        alive = false; return;
    }
    const Vec2 tgt = enemies[targetIndex].pos;
    float dx = tgt.x - pos.x, dy = tgt.y - pos.y;
    float L = std::sqrt(dx*dx + dy*dy);
    if (L > 1e-6f){
        pos.x += dx / L * speed * dt;
        pos.y += dy / L * speed * dt;
    }
    float hx = enemies[targetIndex].pos.x - pos.x;
    float hy = enemies[targetIndex].pos.y - pos.y;
    if ((hx*hx + hy*hy) <= hitRadius*hitRadius){
        enemies[targetIndex].takeDamage(damage, damageType);
        alive = false;
    }
}
