#include <iostream>


bool is_ascending(int array[], int n){

  if (n < 1) {
    return false;
  }
  int value=array[0];
  for (int i = 1; i < n; i++) {
    if (array[i]<value) {
        return false;     
    }   
    if (array[i]>=value) {
        array[i]=value;
    }
  }
  return true;
}




