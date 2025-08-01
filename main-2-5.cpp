#include <iostream>

bool is_descending(int array[], int n);


int main() {
    int arr[] = {9,4,2,1,-4};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    bool result = is_descending(arr, n);
    
    std::cout << "This array is " << result << " for descending." << std::endl;

    return 0;
}

