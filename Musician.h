#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <string>

class Musician {
private:
    int experience;
    std::string instrument;

public:
    Musician();

    Musician(std::string instrument, int experience);
    std::string get_instrument();
    int get_experience();
};

#endif
