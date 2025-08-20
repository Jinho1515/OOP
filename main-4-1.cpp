#include <iostream>


int *readNumbers();
int secondSmallestSum(int *numbers, int length);

int main() {
    int *arr = readNumbers();
    int ans = secondSmallestSum(arr, 10);
    std::cout << ans << '\n';
    delete[] arr;
    return 0;
}
