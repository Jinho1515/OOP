#include <iostream>

int sum_diagonal(int array[4][4]) {
  int sum_mat = 0;

  for (int i = 0; i < 4; i++) {
    sum_mat = sum_mat + array[i][i];
  }
  return sum_mat;
}
