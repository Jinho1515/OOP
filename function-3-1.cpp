#include <iostream>
#include <cmath>

bool is_fanarray(int array[], int n) {

  if (n < 1) {
    return false;
  }
  int middle_num = round(n/2);

  int value=array[0];
  for (int i = 1; i < middle_num; i++) {
    if (array[i]<value) {
        return false;     
    }   
    if (array[i]>=value) {
        array[i]=value;
    }
  }
  for (int i = middle_num; i < n; i++) {
    if (array[i]<value) {
        return false;     
    }   
    if (array[i]>=value) {
        array[i]=value;
    }
  }
  return true;
}




