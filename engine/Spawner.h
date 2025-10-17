#pragma once
#include <vector>
#include <string>
#include "World.h"
#include "Adapters.h"

class Spawner {
public:
    // config/state
    std::vector<std::string> types; // {"goblin","goblin","ogre",...}
    size_t nextIndex = 0;

    float spawnInterval = 0.5f; // seconds between spawns
    float spawnTimer    = 0.0f; // accumulator

    void loadWave(const std::vector<std::string>& t, float intervalSec){
        types = t; nextIndex = 0; spawnInterval = intervalSec; spawnTimer = 0.0f;
    }
    bool done() const { return nextIndex >= types.size(); }

    // pass either dt (real seconds) or dt*world.timeScale (to slow with game speed)
    void update(float dt, World& w){
        if (done() || w.path.nodes.size() < 2) return;
        spawnTimer += dt;
        while (spawnTimer >= spawnInterval && nextIndex < types.size()){
            spawnTimer -= spawnInterval;

            int i = (int)nextIndex;
            EnemyUnit u = makeEnemyUnitFromType(types[i], 1.8f + 0.2f*(i%2));
            u.spawn(w.path);

            // optional: tiny offset so freshly spawned units aren't all at exact same point
            u.t = 0.0f;
            u.pos = w.path.nodes.front();

            w.enemies.push_back(u);
            ++nextIndex;
        }
    }
};
