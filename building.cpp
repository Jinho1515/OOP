#include "building.h"
    
    building::building(){}

    building::building(float damage, int range, float fire_rate, std::string damageType) {
        this->damage = damage;
        this->range = range;
        this->fire_rate = fire_rate;
        this->level = 1;
        this->damageType = damageType;
    }

    // building::~building() {
    // }


    float building::get_damage() {
        return damage;
    }

    int building::get_range() {
        return range;
    }

    float building::get_fire_rate() {
        return fire_rate;
    }

    int building::get_level() {
        return level;
    }

    std::string building::get_damageType() {
        return damageType;
    }


    void building::set_damage(float damage) {
        this->damage = damage;
    }

    void building::set_fire_rate(float fire_rate) {
        this->fire_rate = fire_rate;
    }

    void building::upgrade() {}
    
    // void cost(int money);

    // void building::attack(int enemy) {}
