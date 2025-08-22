#include "Person.h"


PersonList createPersonList(int n) {
  PersonList list{};
  if (n <= 0) {
    list.people = nullptr;
    list.numPeople = 0;
    return list;
  }

  list.numPeople = n;
  list.people = new Person[n];
  for (int i = 0; i < n; ++i) {
    list.people[i].name = "Jane Doe";
    list.people[i].age = 1;
  }
  return list;
}
PersonList deepCopyPersonList(PersonList pl){

    PersonList copy{};
    if (pl.numPeople <= 0 || pl.people==nullptr) {
        copy.people = nullptr;
        copy.numPeople = 0;
        return copy;
    }

    
    copy.numPeople=pl.numPeople;
    copy.people=new Person[copy.numPeople];
 
    for (int i=0; i<copy.numPeople;i++){
        copy.people[i].name = pl.people[i].name;
        copy.people[i].age  = pl.people[i].age;
    }
    return copy;
}