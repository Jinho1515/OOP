#include <iostream>

double weighted_average(int array[], int n);

int main() {
  int arr[] = {1, 2, 1, 4, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  double result = weighted_average(arr, n);
  std::cout << "Weighted average: " << result << std::endl; // Should print 3.0

  return 0;
}
