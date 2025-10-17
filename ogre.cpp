#include "ogre.h"

ogre::ogre(int quantity) : enemy(quantity, 5, 50, "physical") {
    this->quantity = quantity;
}

// int ogre::get_quantity() {
//     return quantity;
// }
