#include "Player.h"

// Constructor
Player::Player(std::string name) {
    this->name = name;
    this->health = 100;
    this->isBlocking = false;
}

// Apply damage to player
void Player::takeDamage(int damage) {
    if (isBlocking) {
        damage /= 2;          // Reduce damage by 50%
        isBlocking = false;   // Blocking only lasts for one attack
    }

    health -= damage;

    if (health < 0) {
        health = 0;           // Prevent negative health
    }
}

// Set blocking state
void Player::setBlocking(bool blocking) {
    isBlocking = blocking;
}

// Get blocking state
bool Player::getIsBlocking() {
    return isBlocking;
}

// Get current health
int Player::getHealth() {
    return health;
}

// Get player name
std::string Player::getName() {
    return name;
}

// Check if player is alive
bool Player::isAlive() {
    return health > 0;
}
