#include "goblin.h"

goblin::goblin(int quantity) : enemy(quantity, 2, 30, "none") {
    this->quantity = quantity;
}

// int goblin::get_quantity() {
//     return quantity;
// }
