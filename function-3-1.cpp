#include <cmath>
#include <iostream>

bool is_fanarray(int array[], int n) {
  if (n < 1) {
    return false;
  }

  int value = array[0];
  int middle_num = n / 2 +1;
  if (n % 2 == 1) {
    int middle_num = round(n / 2);
  }

  for (int i = 1; i < middle_num; i++) {
    if (array[i] < value) {
      return false;
    }
    if (array[i] >= value) {
      array[i] = value;
    }
  }
  for (int i = middle_num; i < n; i++) {
    if (array[i] != array[n - i]) {

        return false;
      }
    
  }
  return true;
}
