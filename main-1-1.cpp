// main-1-1.cpp
#include <iostream>
using namespace std;

int array_sum(int array[], int n);

int main() {
    int data[] = {1, 2, 3, 4, 6};
    int size = sizeof(data) / sizeof(data[0]);

    int result = array_sum(data, size);
    cout << "Sum of array: " << result << endl;

    return 0;
}
