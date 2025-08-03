#include <iostream>


 int median_array(int array[], int n);


int main() {
    int arr[] = {1,5,10,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    int result = median_array(arr, n);
    
    std::cout << "This array has median of " << result << "." << std::endl;

    return 0;
}

