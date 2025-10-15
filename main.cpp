#include <iostream>
#include "Player.h"

int main() {
    Player p1("Alice");

    std::cout << p1.getName() << " starts with health: " << p1.getHealth() << std::endl;

    // Test damage without blocking
    p1.takeDamage(30);
    std::cout << "After 30 damage: " << p1.getHealth() << std::endl;

    // Test blocking
    p1.setBlocking(true);
    p1.takeDamage(40);
    std::cout << "After blocking 40 damage: " << p1.getHealth() << std::endl;

    // Check alive status
    std::cout << "Is alive? " << (p1.isAlive() ? "Yes" : "No") << std::endl;

    // Test death
    p1.takeDamage(200);
    std::cout << "After overkill: " << p1.getHealth() << ", Alive? " << (p1.isAlive() ? "Yes" : "No") << std::endl;

    return 0;
}
