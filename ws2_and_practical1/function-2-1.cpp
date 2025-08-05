#include <iostream>


int min_element(int array[], int n) {

  if (n < 1) {
    return 0;
  }
  int value=array[0];
  for (int i = 1; i < n; i++) {
    if (value>array[i]) {
        value=array[i];       
    }   
  }
  return value;
}

