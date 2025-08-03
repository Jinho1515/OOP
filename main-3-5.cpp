#include <iostream>


double weighted_average(int array[], int n);


int main() {
    int arr[] = {1,5,10,6,7,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    double result = weighted_average(arr, n);
    
    std::cout << "The sum of even array is " << result << "." << std::endl;

    return 0;
}

