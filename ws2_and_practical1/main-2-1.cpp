#include <iostream>


int min_element(int array[], int n) ;


int main() {
    int arr[] = {1, -5, -5, -3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    int result = min_element(arr, n);
    std::cout << "Smallest number is " << result << std::endl;

    return 0;
}

