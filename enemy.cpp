#include "enemy.h"
        
enemy::enemy(int quantity, int damage, int health, std::string res) {
    this->damage = damage;
    this->health = health;
    this->res = res;
    this->quantity = quantity;
}

enemy::enemy(){
    this->damage = 0;
    this->health = 0;
    this->res = "none";
    this->quantity = 0;   
}

void enemy::take_damage(int damage, std::string dam_type) {
    if (res == dam_type)
    {
        health = health - 0.5*damage;
    } else {
        health = health - damage;
    }
}

int enemy::get_damage() {
    return damage;
}

int enemy::get_health() {
    return health;
}

std::string enemy::get_res() {
    return res;
}