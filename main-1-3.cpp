#include <iostream>

int num_count(int array[], int n, int number);

int main() {
    int arr[] = {1, 3, 5, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = num_count(arr, n, target);
    std::cout << target << " appears " << result << " times in the array." << std::endl;

    return 0;
}

