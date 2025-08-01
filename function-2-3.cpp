#include <iostream>
#include <string>

void two_five_nine(int array[], int n) {
  if (n < 1) {
    return;
  }
  int counter2 = 0;
  int counter5 = 0;
  int counter9 = 0;
  for (int i = 1; i < n; i++) {
    int array_val = array[i];

    switch (array_val) {
      case 2:
        counter2++;
        break;
      case 5:
        counter5++;
        break;
      case 9:
        counter9++;
        break;
    }
  }
  std::cout << "2:" << counter2 << ";5:" << counter5 << ";9:" << counter9
            << std::endl;
}