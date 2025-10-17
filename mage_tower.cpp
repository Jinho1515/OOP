#include "mage_tower.h"

    mage_tower::mage_tower(int location) : building(10, 4, 6, "magic") {
        // add_money(-150);
        this->location = location;
    }

    void mage_tower::upgrade() {
        // add_money(-150*get_level());
        set_damage(get_damage()*1.5);
        level++;
    }

    int mage_tower:: get_location() {
        return location;
    }

    // void mage_tower::attack(int enemy) {
        //need enemy to deal damage
    // }

   