#include <iostream>

int sum_two_arrays(int array[], int secondarray[], int n) {
  

  if (n < 1) {
    return 0;
  }
  int sum_arr1=0, sum_arr2=0;
  for (int i = 0; i < n; i++) {
    sum_arr1= sum_arr1 + array[i];
    sum_arr2= sum_arr2 + secondarray[i];
    }
   int sum_total= sum_arr1 +sum_arr2;
  return sum_total;
}
