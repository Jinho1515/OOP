#include "World.h"
#include "player.h"
#include <algorithm>

void World::addLives(int delta){
    if (!playerRef) return;
    playerRef->add_health(delta);
}

void World::setTimeScale(float s){
    if (s < 0.1f) s = 0.1f;
    if (s > 5.0f) s = 5.0f;
    timeScale = s;
}

void World::update(float dt){
    // 1) enemies move
    for (auto& e : enemies) e.update(path, dt);

    // 2) towers act
    for (auto& t : towers) t.update(dt, enemies, projectiles);

    // 3) projectiles move & hit
    for (auto& p : projectiles) p.update(enemies, dt);

    // 3.5) pay bounties for enemies that died this tick
    if (playerRef){
        for (auto& e : enemies){
            if (e.dead && !e.escaped && !e.bountyPaid){
                playerRef->add_money(e.bounty);
                e.bountyPaid = true;
            }
        }
    }

    // 4) handle escapes (reduce lives)
    int escapes = 0;
    for (auto& e : enemies) if (e.escaped && !e.dead) escapes++;
    if (escapes) addLives(-escapes);

    // 5) cleanup
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [](const Projectile& p){ return !p.alive; }), projectiles.end());
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](const EnemyUnit& e){ return e.dead || e.escaped; }), enemies.end());
}

