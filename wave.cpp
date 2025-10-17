#include "wave.h"
#include "goblin.h"
#include "ogre.h"
#include "skeleton.h"
#include "enemy.h"
  
wave::wave(int* quantity_array, std::string* type_array) {    
    wave_enemies = new enemy*[5];
    // this->quantity_array = quantity_array;
    // this->type_array = type_array;
    this->quantity_array = new int[5];
    this->type_array = new std::string[5];
for (int i = 0; i < 5; ++i) {
    this->quantity_array[i] = quantity_array[i];
    this->type_array[i] = type_array[i];
}
    for (int i = 0; i < 5; i++)
    {
        if (type_array[i] == "goblin") {
    wave_enemies[i] = new goblin(quantity_array[i]);
}
else if (type_array[i] == "ogre") {
    wave_enemies[i] = new ogre(quantity_array[i]);
}   
else if (type_array[i] == "skeleton") {
    wave_enemies[i] = new skeleton(quantity_array[i]);
}
else {
    wave_enemies[i] = nullptr; // or throw an error
}
    }
    

}

enemy** wave::get_wave_enemies() {
    return wave_enemies;
}

// wave::~wave() {
//     for (int i = 0; i < 5; i++) {
//         delete wave_enemies[i];
//     }
//     delete[] wave_enemies;

//     delete[] quantity_array;
//     delete[] type_array;
// }