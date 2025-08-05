#include <iostream>


int sum_two_arrays(int array[], int secondarray[], int n);

int main() {
    int arr1[] = {1, 3, 5, 3, 3, 3};
    int arr2[] = {3, 5, 6, 4, 7, -3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    

    int result = sum_two_arrays(arr1, arr2, n);
    std::cout << " Sum two arr is " << result <<  std::endl;

    return 0;
}

