#ifndef GOBLIN_H
#define GOBLIN_H

    #include "enemy.h"

    class goblin : public enemy
    {
    private:
        int quantity;
    public:
        goblin(int quantity);

        // int get_quantity();
    };
    
#endif