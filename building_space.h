#ifndef BUILDING_SPACE_H
#define BUILDING_SPACE_H

    #include "building.h"

    class building_space : public building
    {
    private: 
        int total_space;
        building** space;
        int occupied;
    public:
        building_space(int total_space);

        building** get_space();

        bool popularise(building* type);


        // ~building_space();
    };

#endif