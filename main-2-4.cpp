#include <iostream>
using namespace std;

int array_min(const int integers[], int length);
int array_max(const int integers[], int length);
int sum_min_max(const int integers[], int length);

int main() {
    int arr1[] = {4, 7, 1, 9, 3};
    int arr2[] = {}; // empty

    cout << "Array 1 min: " << array_min(arr1, 5) << "\n";
    cout << "Array 1 max: " << array_max(arr1, 5) << "\n";
    cout << "Array 1 sum of min + max: " << sum_min_max(arr1, 5) << "\n\n";

    cout << "Array 2 min: " << array_min(arr2, 0) << "\n";
    cout << "Array 2 max: " << array_max(arr2, 0) << "\n";
    cout << "Array 2 sum of min + max: " << sum_min_max(arr2, 0) << "\n";

    return 0;
}
