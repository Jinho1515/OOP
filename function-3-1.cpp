#include <iostream>

bool is_fanarray(int array[], int n) {
  if (n < 1) {
    return false;
  }

  int middle = n / 2;

  // Check ascending order to middle
  for (int i = 1; i <= middle; i++) {
    if (array[i] < array[i - 1]) {
      return false;
    }
  }

  // Check palindrome
  for (int i = 0; i < n / 2; i++) {
    if (array[i] != array[n - 1 - i]) {
      return false;
    }
  }

  return true;
}
