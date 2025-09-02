#include "warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(std::string name, int health, int damage, std::string weapon)
    : Player(name, health, damage), weapon(weapon)
{
}

const std::string& Warrior::getWeapon() const
{
    return weapon;
}

void Warrior::setWeapon(const std::string& w)
{
    weapon = w;
}

void Warrior::swingWeapon(Player* opponent)
{
    if (!opponent || health <= 0) {
        return;
    }

    cout << name << " swings their " << weapon
         << " at " << opponent->getName() << "!\n";

    // warrior deals base damage regardless of weapon type
    attack(opponent, damage);
}
