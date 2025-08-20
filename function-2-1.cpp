#include <iostream>

int *readNumbers() {
    int *arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}

void hexDigits(int *numbers, int length) {
    for (int i = 0; i < length; ++i) {
        char hexChar;
        switch (numbers[i]) {
            case 0:  hexChar = '0'; break;
            case 1:  hexChar = '1'; break;
            case 2:  hexChar = '2'; break;
            case 3:  hexChar = '3'; break;
            case 4:  hexChar = '4'; break;
            case 5:  hexChar = '5'; break;
            case 6:  hexChar = '6'; break;
            case 7:  hexChar = '7'; break;
            case 8:  hexChar = '8'; break;
            case 9:  hexChar = '9'; break;
            case 10: hexChar = 'A'; break;
            case 11: hexChar = 'B'; break;
            case 12: hexChar = 'C'; break;
            case 13: hexChar = 'D'; break;
            case 14: hexChar = 'E'; break;
            case 15: hexChar = 'F'; break;
        }
        std::cout << i << ' ' << numbers[i] << ' ' << hexChar << '\n';
    }
}
