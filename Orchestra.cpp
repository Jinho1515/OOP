#include "Orchestra.h"
#include <iomanip>

Orchestra::Orchestra(){
    max=0;
    count=0;
    members=nullptr;
}
Orchestra::Orchestra(int size) {
    max=size;
    count=0;
    if (size>0) {
        members = new Musician[size];
    } else {
        members=nullptr;
    }
  }

  int Orchestra::get_current_number_of_members(){
    return count;
  }

  Musician* Orchestra::get_members() {
    return members;
}

bool Orchestra::has_instrument(std::string instrument) {
    for (int i=0;i<count;i++) {
        if (members[i].get_instrument()==instrument){
            return true;
        }
    }
    return false;
 }

   bool Orchestra::add_musician(Musician new_musician){
    if (count<max) {
        members[count]=new_musician;
        count++;
        return true;
    }
    return false;
   }

    Orchestra::~Orchestra() {
        delete[] members;

    }
