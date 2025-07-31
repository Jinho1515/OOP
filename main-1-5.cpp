#include <iostream>


int count_evens(int number);

int main() {
    int numbers = 50;
    

    int result = count_evens(numbers);
    std::cout << " number of even between 1 to " << numbers << " is " << result <<  std::endl;

    return 0;
}

