#include <iostream>

bool is_fanarray(int array[], int n);


int main() {
    int arr[] = {1,2,4,3,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    

    bool result = is_fanarray(arr, n);
    
    std::cout << "This array is " << result << " for fanarray." << std::endl;

    return 0;
}

