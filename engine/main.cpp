#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include "World.h"
#include "player.h"
#include "building_space.h"
#include "Adapters.h"
#include "Spawner.h"


// --- Economy helpers ---
static int towerCost(int type){
    // 1: Ballista, 2: Mage, 3: Farm (example)
    if (type == 1) return 100;
    if (type == 2) return 140;
    if (type == 3) return 50;
    return 100;
}
static int refundAmount(int cost){ return cost * 70 / 100; } // 70% refund when selling the bulding


static void seedPath(World& w){
    // so ts is right -> up -> right
    w.path.nodes = { {0,0}, {8,0}, {8,4}, {14,4} };
}
static void seedSlots(World& w){
    // Developer-chosen buildable coordinates
    w.slots.positions = { {3,1}, {6,2}, {9,3}, {12,5} };
}



static void interactiveBuild(World& w, std::vector<building*>& ownedRawPtrs){
    if (!w.playerRef){
        std::cout << "Error: World.playerRef is null.\n";
        return;
    }
    player& plr = *w.playerRef;

    struct Owned { building* b; int slot; int cost; };
    std::vector<Owned> owned; owned.reserve(w.slots.positions.size());

    auto slotOccupied = [&](int slot)->bool{
        for (auto& t : w.towers){
            if (t.pos.x == w.slots.positions[slot].x &&
                t.pos.y == w.slots.positions[slot].y) return true;
        }
        return false;
    };
    auto findOwnedBySlot = [&](int slot)->int{
        for (int i=0;i<(int)owned.size();++i) if (owned[i].slot == slot) return i;
        return -1;
    };

    std::cout << "=== BUILD PHASE ===\n";
    std::cout << "Slots:\n";
    for (size_t i=0;i<w.slots.positions.size();++i){
        std::cout << "  [" << i << "] (" << w.slots.positions[i].x << "," << w.slots.positions[i].y << ")\n";
    }
    std::cout << "Tower types: (1) Ballista ($" << towerCost(1)
              << ")  (2) Mage ($" << towerCost(2)
              << ")  (3) Farm ($" << towerCost(3) << ")\n";
    std::cout << "Commands:\n"
              << "  <slot> <type>   -> build (e.g., '0 1')\n"
              << "  sell <slot>     -> refund 70% and free the slot\n"
              << "  list            -> show placed towers\n"
              << "  gold            -> show your gold\n"
              << "  start           -> begin wave\n";
    std::cout << "Gold: $" << plr.get_money() << " | Lives: " << plr.get_health() << "\n";

    while (true){
        std::cout << "> ";
        std::string cmd;
        if (!(std::cin >> cmd)) return;

        if (cmd == "start") break;

        if (cmd == "gold"){
            std::cout << "Gold: $" << plr.get_money() << "\n";
            continue;
        }
        if (cmd == "list"){
            if (owned.empty()) { std::cout << "(no towers)\n"; continue; }
            for (auto& o : owned){
                std::cout << "  slot " << o.slot << "  cost $" << o.cost << "\n";
            }
            continue;
        }
        if (cmd == "sell"){
            int slot; 
            if (!(std::cin >> slot)) {
                std::cout << "Usage: sell <slot>\n";
                continue;
            }
            if (slot < 0 || slot >= (int)w.slots.positions.size()){
                std::cout << "Invalid slot.\n";
                continue;
            }
            int idx = findOwnedBySlot(slot);
            if (idx < 0){
                std::cout << "No tower on that slot.\n";
                continue;
            }

            // remove from world.towers by position
            auto pos = w.slots.positions[slot];
            auto itT = std::find_if(w.towers.begin(), w.towers.end(), [&](const TowerUnit& t){
                return t.pos.x == pos.x && t.pos.y == pos.y;
            });
            if (itT != w.towers.end()) w.towers.erase(itT);

            // delete building + refund
            building* b = owned[idx].b;
            delete b;
            int refund = refundAmount(owned[idx].cost);
            plr.add_money(refund);
            std::cout << "Sold slot " << slot << " for $" << refund
                      << ". Gold: $" << plr.get_money() << "\n";

            // bookkeeping
            auto itRaw = std::find(ownedRawPtrs.begin(), ownedRawPtrs.end(), b);
            if (itRaw != ownedRawPtrs.end()) ownedRawPtrs.erase(itRaw);
            owned.erase(owned.begin() + idx);
            continue;
        }

        // build: "<slot> <type>"
        try{
            int slot = std::stoi(cmd);
            int ttype; std::cin >> ttype;

            if (slot < 0 || slot >= (int)w.slots.positions.size()){ std::cout << "Invalid slot.\n"; continue; }
            if (ttype < 1 || ttype > 3){ std::cout << "Invalid tower type.\n"; continue; }
            if (slotOccupied(slot)){ std::cout << "Slot already occupied.\n"; continue; }

            int cost = towerCost(ttype);
            if (plr.get_money() < cost){
                std::cout << "Not enough gold ($" << cost << " needed).\n"; continue;
            }

            // create building (using MR BRIGHT classes)
            building* b = createBuildingByType(ttype, slot);

            // create TowerUnit and add to world (adapts from building getters)
            TowerUnit tu;
            syncTowerUnitFromBuilding(tu, b);
            tu.pos = w.slots.positions[slot];
            w.towers.push_back(tu);

            // pay + record ownership
            plr.add_money(-cost);
            owned.push_back({ b, slot, cost });
            ownedRawPtrs.push_back(b);

            std::cout << "Placed on slot " << slot
                      << ". Gold: $" << plr.get_money() << "\n";
        } catch(...){
            std::cout << "Enter 'start', 'gold', 'list', 'sell <slot>', or '<slot> <type>'.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

//simple wave TYPESHIT
static std::vector<std::vector<std::string>> waves = {
    {"goblin","goblin","goblin","goblin","goblin","goblin"},
    {"goblin","skeleton","goblin","skeleton","goblin","skeleton"},
    {"ogre","goblin","ogre","goblin","skeleton","ogre","goblin"},
};


int main(){
    World world;
    seedPath(world);
    seedSlots(world);

    // Player & lives
    player plr(2);               // difficulty 2 => health 8, money 500
    world.playerRef = &plr;      // <-- this is essential idk why js gpt said otherwise its not work


    // Building spaces (capacity = number of slots)
    ////building_space spaces((int)world.slots.positions.size()); i dont think we need buidling space mr kai bright i can add it tho
    std::vector<building*> owned; owned.reserve(world.slots.positions.size());

    // Build towers (player choice)
    interactiveBuild(world, owned);

//multi wave loop

// helpers reused by command handling
auto slotPos = [&](int slot){ return world.slots.positions[slot]; };
auto slotOccupied = [&](int slot)->bool{
    for (auto& t : world.towers){
        if (t.pos.x == slotPos(slot).x && t.pos.y == slotPos(slot).y) return true;
    }
    return false;
};

bool paused = false;
float dt = 0.05f;            // 50 ms tick
world.setTimeScale(0.6f);    // change live with 'speed x'
int printEvery = 10;         // print every 0.5s

for (size_t wv = 0; wv < waves.size(); ++wv){
    Spawner spawner;
    spawner.loadWave(waves[wv], /*intervalSec=*/0.6f);
    // spawner.spawnTimer = spawner.spawnInterval; // uncomment for instant first spawn

    std::cout << "\n=== WAVE " << (wv+1) << " / " << waves.size()
              << " (type commands while it runs) ===\n";

    for (int step = 0; step < 6000; ++step){
        // ---- 1) commands (type then press Enter) ----
        while (std::cin.rdbuf()->in_avail() > 0){
            std::string cmd; 
            if (!(std::cin >> cmd)) break;

            if (cmd == "pause"){ paused = true;  std::cout << "(paused)\n";  continue; }
            if (cmd == "resume"){ paused = false; std::cout << "(resumed)\n"; continue; }
            if (cmd == "gold"){ std::cout << "Gold: $" << plr.get_money() << "\n"; continue; }
            if (cmd == "list"){
                for (size_t s=0;s<world.slots.positions.size();++s)
                    std::cout << "  slot " << s << (slotOccupied((int)s)? " [OCCUPIED]": "") << "\n";
                continue;
            }
            if (cmd == "speed"){
                float s; if (std::cin >> s){ world.setTimeScale(s); std::cout << "speed=" << s << "\n"; }
                else { std::cout << "Usage: speed <0.1..5>\n"; }
                continue;
            }
            if (cmd == "sell"){
                int slot; 
                if (!(std::cin >> slot)){ std::cout << "Usage: sell <slot>\n"; continue; }
                if (slot < 0 || slot >= (int)world.slots.positions.size()){ std::cout << "Invalid slot.\n"; continue; }

                // remove tower at that slot
                auto pos = slotPos(slot);
                auto itT = std::find_if(world.towers.begin(), world.towers.end(), [&](const TowerUnit& t){
                    return t.pos.x == pos.x && t.pos.y == pos.y;
                });
                if (itT == world.towers.end()){ std::cout << "No tower on that slot.\n"; continue; }

                int refund = refundAmount( (itT->name == "Mage") ? 140 : (itT->name == "Ballista" ? 100 : 50) );
                plr.add_money(refund);
                std::cout << "Sold slot " << slot << " for $" << refund
                          << ". Gold: $" << plr.get_money() << "\n";

                // best-effort delete of a created building*
                if (!owned.empty()){ delete owned.back(); owned.pop_back(); }
                world.towers.erase(itT);
                continue;
            }
            if (cmd == "b" || cmd == "build"){
                int slot, ttype;
                if (!(std::cin >> slot >> ttype)){ std::cout << "Usage: b <slot> <type>\n"; continue; }
                if (slot < 0 || slot >= (int)world.slots.positions.size()){ std::cout << "Invalid slot.\n"; continue; }
                if (ttype < 1 || ttype > 3){ std::cout << "Invalid type (1=Ballista, 2=Mage, 3=Farm)\n"; continue; }
                if (slotOccupied(slot)){ std::cout << "Slot already occupied.\n"; continue; }

                int cost = (ttype == 1? 100 : ttype == 2? 140 : 50);
                if (plr.get_money() < cost){ std::cout << "Not enough gold ($" << cost << ").\n"; continue; }

                building* b = createBuildingByType(ttype, slot);
                TowerUnit tu; syncTowerUnitFromBuilding(tu, b);
                tu.pos = slotPos(slot);

                world.towers.push_back(tu);
                owned.push_back(b);       // track for cleanup
                plr.add_money(-cost);

                std::cout << "Built on slot " << slot << ". Gold: $" << plr.get_money() << "\n";
                continue;
            }

            std::cout << "Commands: b <slot> <type> | sell <slot> | speed <x> | pause | resume | gold | list\n";
        }

        // ---- 2) spawns before the sim tick ----
        spawner.update(dt * world.timeScale, world);   // or pass dt if spawns shouldn't scale

        // ---- 3) simulation tick ----
        if (!paused) world.update(dt);

        // ---- 4) status line ----
        if (step % printEvery == 0){
            std::cout << "t=" << std::setw(5) << std::fixed << std::setprecision(1) << step*dt
                      << "s  | Enemies=" << world.enemies.size()
                      << " | Projectiles=" << world.projectiles.size()
                      << " | Lives=" << plr.get_health()
                      << " | Gold="  << plr.get_money()
                      << " | speed=" << world.timeScale << "\n";
        }

        // ---- 5) end conditions for this wave ----
        if ((spawner.done() && world.enemies.empty()) || plr.get_health() <= 0) break;

        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // pacing
    }

    if (plr.get_health() <= 0){
        std::cout << "Defeat on wave " << (wv+1) << ".\n";
        break;
    } else {
        std::cout << "Wave " << (wv+1) << " cleared!\n";
        // Optional: inter-wave bonus
        // plr.add_money(50);
    }
}

if (plr.get_health() > 0){
    std::cout << "All waves cleared!\n";
}

// cleanup
for (auto* b : owned) delete b;
return 0;
}

