#ifndef ENEMY_H
#define ENEMY_H

    #include <string>

    class enemy
    {
    private:
        int damage;
        int health;
        std::string res;
        int quantity;
    public:

        enemy();

        enemy(int quantity, int damage, int health, std::string res);

        void take_damage(int damage, std::string dam_type);

        int get_damage();

        int get_health();

        std::string get_res();

        // virtual ~enemy();
    };
    
#endif