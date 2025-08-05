// main-1-2.cpp
#include <iostream>

double array_mean(int array[], int n);

int main() {
    int my_array[] = {4, 5, 6, 7};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    double avg = array_mean(my_array, n);
    std::cout << "Mean of array: " << avg << std::endl;

    return 0;
}
