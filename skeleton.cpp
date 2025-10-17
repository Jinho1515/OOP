#include "skeleton.h"

skeleton::skeleton(int quantity) : enemy(quantity, 2, 20, "magical") {
    this->quantity = quantity;
}

// int skeleton::get_quantity() {
//     return quantity;
// }
