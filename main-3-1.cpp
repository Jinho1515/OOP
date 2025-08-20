#include <iostream>

// Forward declarations
int *readNumbers();
bool equalsArray(int *numbers1, int *numbers2, int length);

int main() {
    int *arr1 = readNumbers();
    int *arr2 = readNumbers();

    bool result = equalsArray(arr1, arr2, 10);
    std::cout << (result ? "true" : "false") << std::endl;

    delete[] arr1;
    delete[] arr2;
    return 0;
}
