#include <iostream>

#include "workshop.h"

int main() {
  // Part 1
  double d = 3.14159;
  char c = 'A';

  double* pd = &d;  // pointer to double, holds address of d
  char* pc = &c;    // pointer to char, holds address of c

  // Print values via the pointers (dereference with *)
  std::cout << "double via pointer: " << *pd << "\n";
  std::cout << "char via pointer (as character): " << *pc << "\n";
  // (optional extra line to see the numeric code of the char)
  std::cout << "char via pointer (as int code): " << static_cast<int>(*pc)
            << "\n";

  // part 2
  std::cout << "Part 2\n";
  std::cout << "Before changeValue: d = " << d << "\n";
  changeValue(&d);
  std::cout << "After  changeValue: d = " << d << "\n";


  // part 3
  std::cout << "Part 3\n";
  double a[] = {1.1, -2.5, 3.0, 9.9, 4.2};
  int n = static_cast<int>(sizeof(a) / sizeof(a[0]));
  std::cout << "Array: ";
  printArray(a, n);
  std::cout << "\n";

  // part 4
  std::cout << "Part 4\n";
  double m = arrayMax(a, n);
  std::cout << "Max of static array = " << m << "\n\n";

  std::cout << "part 5 and 6\n";
  int N = 5;
  double* arr = dynamicArray(N);
  printArray(arr, N);
  std::cout << arrayMax(arr, N) << "n";
  delete[] arr;

  std::cout << "=== Part 7 ===\n";
  double fill = -7.0;
  double* dynFill = dynamicArray(4, fill); 
  printArray(dynFill, 4);
  std::cout << "Max of dynFill = " << arrayMax(dynFill, 4) << "\n";
  delete[] dynFill;
  std::cout << "(deleted dynFill)\n\n";
}
