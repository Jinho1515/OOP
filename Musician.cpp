#include "Musician.h"

Musician::Musician() {
    instrument="null";
    experience=0;
}

Musician::Musician(std::string instrument, int experience) {
    this->experience=experience; //Left side (this->experience) →
    // the private variable inside the object (declared in Musician.h):
    //Right side (experience) → the parameter passed into the constructor.
    //It only exists temporarily while the constructor is running.
    this->instrument=instrument;
}

std::string Musician::get_instrument(){
    return instrument;
}

int Musician::get_experience(){
    return experience;
}
