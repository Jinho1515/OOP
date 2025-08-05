#include <iostream>
#include <algorithm>

 int median_array(int array[], int n) {
  if (n < 1 || n % 2 ==0) {
    return false;
  }

  std::sort(array, array + n);

  return array[n/2];
}