#ifndef BUILDING_H
#define BUILDING_H

// #include "player.h"
#include <string>

class building
{
private:
    float damage; //float for multipliers
    int range;
    float fire_rate;
    std::string damageType;
    // std::string priority;  for if we get to it
protected:
    int level;
public:
    building();

    building(float damage, int range, float fire_rate, std::string damageType);

    virtual ~building() = default;

    float get_damage();

    int get_range();

    float get_fire_rate();

    int get_level();

    std::string get_damageType();

    void set_damage(float damage);

    void set_fire_rate(float fire_rate);

    void cost(int money);

    // void set_priority(std::string priority);

    virtual void upgrade();

    // virtual void attack(int enemy);
};

#endif