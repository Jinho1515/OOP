#include <iostream>

double array_mean(int array[], int n) {
  double sum_arr = 0;

  if (n < 1) {
    return 0.0;
  }
  for (int i = 0; i < n; i++) {
    if (array[i] > 1) {
      sum_arr = sum_arr + array[i];
      
    }
  }
  double ave_arr = sum_arr/n;
  return sum_arr / n;
}
