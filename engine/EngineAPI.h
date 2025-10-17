#pragma once
#include <vector>
#include <string>
#include "World.h"
#include "Spawner.h"
#include "Adapters.h"
#include "player.h"

struct EnemyView { float x, y; int hp, max_hp; bool dead, escaped; };
struct TowerView  { float x, y; float range; const char* name; };
struct ProjView   { float x, y; };
struct GameState {
    std::vector<EnemyView> enemies;
    std::vector<TowerView> towers;
    std::vector<ProjView>  projectiles;
    int lives = 0, gold = 0;
    float timeScale = 1.0f;
    bool waveDone = false;
};

class Engine {
public:
    Engine();
    ~Engine();

    // setup
    void loadDefaultMap();                        // seeds path + slots
    void setDifficulty(int d);                    // sets player health/money
    void setTimeScale(float s);
    float getTimeScale() const { return world.timeScale; }

    // waves
    void startWave(const std::vector<std::string>& types, float intervalSec);
    bool isWaveActive() const;                    // spawner not done || enemies exist

    // actions
    bool build(int slot, int towerType, int* outCost=nullptr);
    bool sell(int slot, int* outRefund=nullptr);

    // step simulation
    void tick(float dt);                          // UI calls every frame (e.g., 1/60)

    // view for rendering
    GameState getState() const;

    // helpers for UI
    int  slotCount() const { return (int)world.slots.positions.size(); }
    Vec2 slotPos(int i) const { return world.slots.positions[i]; }
    bool slotOccupied(int slot) const;

private:
    struct Placed { int slot; int cost; building* ptr; };
    World world;
    player plr{2};
    Spawner spawner;
    std::vector<building*> owned;  // for cleanup
    std::vector<Placed> placed;    // for accurate refunds

    int towerCost(int type) const;
    int refundAmount(int cost) const { return cost * 70 / 100; }
};
