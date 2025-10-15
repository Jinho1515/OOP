#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;   // Name of the player
    int health;         // Current HP
    bool isBlocking;    // Whether player is currently blocking

public:
    // Constructor
    Player(std::string name);

    // Public Methods
    void takeDamage(int damage);
    void setBlocking(bool blocking);
    bool getIsBlocking();
    int getHealth();
    std::string getName();
    bool isAlive();
};

#endif
