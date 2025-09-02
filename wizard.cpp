#include "wizard.h"

#include <iostream>
using namespace std;

Wizard::Wizard(std::string name, int health, int damage, int mana)
    : Player(name, health, damage), mana(mana) {}

int Wizard::getMana() const { return mana; }

void Wizard::setMana(int m) { mana = m; }

void Wizard::castSpell(Player* opponent) {
  if (!opponent || health <= 0) {
    return;
  }

  int dealt = mana;  // wizard deals damage equal to mana
  cout << name << " casts a spell on " << opponent->getName() << " for "
       << dealt << " damage.\n";

  attack(opponent, dealt);
}
