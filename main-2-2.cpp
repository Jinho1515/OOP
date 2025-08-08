#include <iostream>
using namespace std;

int binary_to_int(int binary_digits[], int number_of_digits);

int main() {
    int a1[] = {1,0,1,1};          // 11
    int a2[] = {1,0,0,0,0};        // 16
    int a3[] = {1,1,1,1,1};        // 31

    cout << binary_to_int(a1, 4) << "\n";
    cout << binary_to_int(a2, 5) << "\n";
    cout << binary_to_int(a3, 5) << "\n";
    return 0;
}
