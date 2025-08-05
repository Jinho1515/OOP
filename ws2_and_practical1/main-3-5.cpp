#include <iostream>


 double sum_even(double array[], int n);


int main() {
    double arr[] = {1,5,10,6,7,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    double result = sum_even(arr, n);
    
    std::cout << "The sum of even array is " << result << "." << std::endl;

    return 0;
}

