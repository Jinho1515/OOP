#include <iostream>

void count_digits(int array[4][4]);

int main() {
    int matrix[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    count_digits(matrix);

    return 0;
}
