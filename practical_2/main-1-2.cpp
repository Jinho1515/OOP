#include <iostream>


int is_identity(int array[10][10]);

int main() {
    int matrix[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        matrix[i][i] = 1;
    }

    int result = is_identity(matrix);

    if (result == 1) {
        std::cout << "Matrix is an identity matrix." << std::endl;
    } else {
        std::cout << "Matrix is NOT an identity matrix." << std::endl;
    }

    return 0;
}
