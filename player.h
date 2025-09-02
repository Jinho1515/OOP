#pragma once
#include <string>

class Player {
 protected:
  std::string name;
  int health;
  int damage;

 public:
  Player(std::string name, int health, int damage);
  virtual ~Player() = default;

  // getters
  const std::string& getName() const;
  int getHealth() const;
  int getDamage() const;

  // setters
  void setName(const std::string& n);
  void setHealth(int h);
  void setDamage(int d);

  // actions
  void attack(Player* opponent, int dmg);
  void takeDamage(int dmg);
};
