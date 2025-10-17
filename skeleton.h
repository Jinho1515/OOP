#ifndef SKELETON_H
#define SKELETON_H

    #include "enemy.h"

    class skeleton : public enemy
    {
    private:
        int quantity;
    public:
        skeleton(int quantity);

        // int get_quantity();
    };
    
#endif