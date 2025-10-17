#include "player.h"
#include "ballista.h"
#include "farm.h"
#include "mage_tower.h"
#include "building_space.h"
#include "wave.h"
#include <iostream>

int main() {
    // intialise player
    player Plr(2);

    // setting how many spaces are availible for buildings
    building_space MAP1(4);

    // building placement 
    ballista B1(1);
    mage_tower MT1(2);
    farm F1(3);
    ballista B2(4);

    MAP1.popularise(&B1);
    MAP1.popularise(&MT1);
    MAP1.popularise(&F1);
    MAP1.popularise(&B2);

    // geting a variable type
    std::cout << MAP1.get_space()[0]->get_damageType() << std::endl;

    // setting a variable
    std::cout << "initial damage: " << MAP1.get_space()[0]->get_damage() << std::endl;
    MAP1.get_space()[0]->set_damage(10);
    std::cout << "final damage: " << MAP1.get_space()[0]->get_damage() << std::endl;

    // upgrade a building
    std::cout<< "initial level: " << MAP1.get_space()[0]->get_level() << " with intial fire rate: " 
    << MAP1.get_space()[0]->get_fire_rate() << std::endl;

    MAP1.get_space()[0]->upgrade();

    std::cout<< "initial level: " << MAP1.get_space()[0]->get_level() << " with intial fire rate: " 
    << MAP1.get_space()[0]->get_fire_rate() << std::endl;

    MAP1.get_space()[0]->upgrade();

    std::cout<< "initial level: " << MAP1.get_space()[0]->get_level() << " with intial fire rate: " 
    << MAP1.get_space()[0]->get_fire_rate() << std::endl;

    


    // intitalise ememy

    int quantity_enemy[5] = {1,0,3,2,1};
    std::string enemy_type[5] = {"goblin", "goblin", "skeleton", "goblin", "ogre"};

    wave W1(quantity_enemy, enemy_type);
    
    enemy** check = W1.get_wave_enemies();

    std::cout << check[4]->get_health() << std::endl ;
}