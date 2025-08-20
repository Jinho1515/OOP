
#include <iostream>

void changeValue(double* p) {
  if (p) {
    *p = 42.0;
  }
}

void printArray(double* a, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

double arrayMax(double* a, int n) {
  double maxVal = a[0];
  for (int i = 0; i < n; i++) {
    if (maxVal < a[i]) {
      maxVal = a[i];
    }
  }

  return maxVal;
}

double* dynamicArray(int N) {
  if (N <= 0) {
    return nullptr;
  }
  double* arr = new double[N];
  for (int i = 0; i < N; ++i) {
    arr[i] = static_cast<double>(i);
  }
  return arr;
}
double* dynamicArray(int N, double M) {
  if (N <= 0) {
    return nullptr;
  }
  double* arr = new double[N];
  for (int i = 0; i < N; ++i) {
    arr[i] = M;
  }
  return arr;
}