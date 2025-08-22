#include <iostream>
#include "Person.h"

PersonList createPersonList(int n); 
PersonList shallowCopyPersonList(PersonList pl);

int main() {
    PersonList a = createPersonList(3);

    PersonList b = shallowCopyPersonList(a);

    b.people[1].name = "SharedChange";
    b.people[2].age  = 99;


    for (int i = 0; i < a.numPeople; ++i) {
        std::cout << "  " << i << ": " << a.people[i].name
                  << ", age " << a.people[i].age << "\n";
    }

    for (int i = 0; i < b.numPeople; ++i) {
        std::cout << "  " << i << ": " << b.people[i].name
                  << ", age " << b.people[i].age << "\n";
    }

    return 0;
}
