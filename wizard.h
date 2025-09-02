#pragma once
#include "player.h"

class Wizard : public Player {
    int mana;

public:
    Wizard(std::string name, int health, int damage, int mana);

    int getMana() const;
    void setMana(int m);

    void castSpell(Player* opponent);
};
