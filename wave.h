#ifndef WAVE_H
#define WAVE_H

    #include "enemy.h"

    class wave : public enemy
    {
    private:
        // int E1;
        // int E2;
        // int E3;
        // int E4;
        // int E5;
        // int size;
        // std::string goblin;
        // std::string ogre;
        // std::string skeleton;
        // std::string type1;
        // std::string type2;
        // std::string type3;
        // std::string type4;
        // std::string type5;
        enemy** wave_enemies;
        int* quantity_array;
        std::string* type_array;
    public:
    //     wave(int E1, std::string type1, int E2, std::string type2, int E3, 
    //         std::string type3, int E4, std::string type4, int E5, std::string type5);

        wave(int* quantity_array, std::string* type_array);

        enemy **get_wave_enemies();

        // ~wave();
    };
    
#endif