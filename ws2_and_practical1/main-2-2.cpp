#include <iostream>


int max_element(int array[], int n);


int main() {
    int arr[] = {1, -5, -5, -3, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    int result = max_element(arr, n);
    std::cout << "Highest number is " << result << std::endl;

    return 0;
}

