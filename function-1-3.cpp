#include <iostream>
using namespace std;

void count_digits(int array[4][4]) {
    int counts[10] = {0}; 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = array[i][j];
            if (value >= 0 && value <= 9) {
                counts[value]++;
            }
        }
    }

    for (int k = 0; k < 10; k++) {
        std::cout << k << ":" << counts[k] << ";";
    }
    cout << endl;
}
