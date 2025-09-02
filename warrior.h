#pragma once
#include <string>

#include "player.h"

class Warrior : public Player {
  std::string weapon;

 public:
  Warrior(std::string name, int health, int damage, std::string weapon);
  const std::string& getWeapon() const;
  void setWeapon(const std::string& w);

  void swingWeapon(Player* opponent);
};
