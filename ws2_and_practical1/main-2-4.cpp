#include <iostream>


bool is_ascending(int array[], int n);


int main() {
    int arr[] = {1, 5, 5, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    bool result = is_ascending(arr, n);
    std::cout << "This array is " << result << " for ascending." << std::endl;

    return 0;
}

