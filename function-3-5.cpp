#include <iostream>

 double sum_even(double array[], int n) {
  if (n < 1) {
    return 0.0;
  }

  double total = 0.0;

    // Count frequency of array[i]
    for (int j = 0; j < n; j +=2 ) {
      total = total + array[j];
      }
    

  return total;
}

