#include <iostream>

int array_sum(int array[], int n) {
  int sum_arr = 0;

  if (n < 1) {
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (array[i] > 1) {
      sum_arr = sum_arr + array[i];
      
    }
  }
  return sum_arr;
}
