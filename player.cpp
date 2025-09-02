#include "player.h"

#include <iostream>
using namespace std;

Player::Player(std::string name, int health, int damage)
    : name(name), health(health), damage(damage) {}

const std::string& Player::getName() const { return name; }

int Player::getHealth() const { return health; }

int Player::getDamage() const { return damage; }

void Player::setName(const std::string& n) { name = n; }

void Player::setHealth(int h) { health = h; }

void Player::setDamage(int d) { damage = d; }

void Player::attack(Player* opponent, int dmg) {
  if (!opponent || health <= 0) {
    return;
  }
  opponent->takeDamage(dmg);
}

void Player::takeDamage(int dmg) {
  if (dmg < 0) {
    dmg = 0;
  }
  health -= dmg;
  if (health < 0) {
    health = 0;
  }
  cout << name << " takes " << dmg << " damage. Remaining health: " << health
       << "\n";
}
