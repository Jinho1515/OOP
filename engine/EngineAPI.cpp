#include "EngineAPI.h"
#include <algorithm>

Engine::Engine(){
    world.playerRef = &plr;
}
Engine::~Engine(){
    for (auto* b : owned) delete b;
}

void Engine::loadDefaultMap(){
    // path: right → up → right
    world.path.nodes = { {0,0}, {8,0}, {8,4}, {14,4} };
    // build slots (dev-chosen)
    world.slots.positions = { {3,1}, {6,2}, {9,3}, {12,5} };
}
void Engine::setDifficulty(int d){
    plr = player(d);
    world.playerRef = &plr;
}
void Engine::setTimeScale(float s){ world.setTimeScale(s); }

int Engine::towerCost(int type) const {
    if (type==1) return 100; // Ballista
    if (type==2) return 140; // Mage
    if (type==3) return 50;  // Farm
    return 100;
}

void Engine::startWave(const std::vector<std::string>& types, float intervalSec){
    spawner.loadWave(types, intervalSec);
    // Want instant first spawn? spawner.spawnTimer = spawner.spawnInterval;
}
bool Engine::isWaveActive() const {
    return !spawner.done() || !world.enemies.empty();
}

bool Engine::slotOccupied(int slot) const {
    auto p = world.slots.positions[slot];
    for (auto& t : world.towers)
        if (t.pos.x==p.x && t.pos.y==p.y) return true;
    return false;
}

bool Engine::build(int slot, int ttype, int* outCost){
    if (slot < 0 || slot >= slotCount()) return false;
    if (ttype < 1 || ttype > 3) return false;
    if (slotOccupied(slot)) return false;

    int cost = towerCost(ttype);
    if (plr.get_money() < cost) return false;

    building* b = createBuildingByType(ttype, slot);

    TowerUnit tu; syncTowerUnitFromBuilding(tu, b);
    tu.pos = world.slots.positions[slot];
    world.towers.push_back(tu);

    owned.push_back(b);
    placed.push_back({slot, cost, b});
    plr.add_money(-cost);
    if (outCost) *outCost = cost;
    return true;
}

bool Engine::sell(int slot, int* outRefund){
    auto itP = std::find_if(placed.begin(), placed.end(),
        [&](const Placed& p){ return p.slot==slot; });
    if (itP == placed.end()) return false;

    // remove tower
    auto pos = world.slots.positions[slot];
    auto itT = std::find_if(world.towers.begin(), world.towers.end(),
        [&](const TowerUnit& t){ return t.pos.x==pos.x && t.pos.y==pos.y; });
    if (itT != world.towers.end()) world.towers.erase(itT);

    int refund = refundAmount(itP->cost);
    plr.add_money(refund);
    delete itP->ptr;
    auto itRaw = std::find(owned.begin(), owned.end(), itP->ptr);
    if (itRaw != owned.end()) owned.erase(itRaw);
    placed.erase(itP);
    if (outRefund) *outRefund = refund;
    return true;
}

void Engine::tick(float dt){
    // spawns (respect speed)
    spawner.update(dt * world.timeScale, world);

    // world step
    world.update(dt);
}

GameState Engine::getState() const {
    GameState gs;
    gs.lives = plr.get_health();
    gs.gold  = plr.get_money();
    gs.timeScale = world.timeScale;
    gs.waveDone  = spawner.done() && world.enemies.empty();

    gs.enemies.reserve(world.enemies.size());
    for (auto& e : world.enemies){
        gs.enemies.push_back({e.pos.x, e.pos.y, e.hp, e.max_hp, e.dead, e.escaped});
    }
    gs.towers.reserve(world.towers.size());
    for (auto& t : world.towers){
        gs.towers.push_back({t.pos.x, t.pos.y, t.range, t.name.c_str()});
    }
    gs.projectiles.reserve(world.projectiles.size());
    for (auto& p : world.projectiles){
        gs.projectiles.push_back({p.pos.x, p.pos.y});
    }
    return gs;
}
