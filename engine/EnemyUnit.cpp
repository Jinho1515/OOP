#include "EnemyUnit.h"
#include <algorithm>

void EnemyUnit::spawn(const Path& p){
    seg = 0; t = 0.f; dead=false; escaped=false;
    hp = max_hp;
    pos = p.valid()? p.nodes.front() : Vec2();
}
// like how they move typeshi (the goat did it)
void EnemyUnit::update(const Path& p, float dt){
    if (dead || escaped || !p.valid() || speed<=0) return;
    float move = speed * dt;
    while (move > 0 && !escaped){
        if (seg+1 >= (int)p.nodes.size()) { escaped = true; break; }
        Vec2 A = p.nodes[seg], B = p.nodes[seg+1];
        float L = dist(A,B);
        if (L <= 1e-6f) { seg++; t=0; pos=B; continue; }
        float left = (1.f - t) * L;
        if (move < left){
            t += move / L;
            pos = lerp(A,B,t);
            move = 0;
        } else {
            move -= left;
            seg++; t = 0; pos = B;
            if (seg+1 >= (int)p.nodes.size()) escaped = true;
        }
    }
}

void EnemyUnit::takeDamage(int dmg, const std::string& dam_type){
    if (dead) return;
    int delt = dmg;
    if (dam_type == res) delt = dmg / 2; //  resistance CALCULATION
    hp -= std::max(0, delt);
    if (hp <= 0) dead = true;
}
