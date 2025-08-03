#include <iostream>

void print_pass_fail(char grade) {
  switch (grade) {
    case 'A':
    case 'B':
    case 'C':
      std::cout << "Pass\n";
      break;
    case 'D':
    case 'E':
      std::cout << "Fail\n";
      break;
    default:
      std::cout << "Nothing\n";
      break;
  }
}
