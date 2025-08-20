#include <iostream>
#include <climits>

int *readNumbers() {
    int *arr = new int[10];
    for (int i = 0; i < 10; ++i) std::cin >> arr[i];
    return arr;
}

int secondSmallestSum(int *numbers, int length) {
   
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < length; ++i) {
        int running = 0;
        for (int j = i; j < length; ++j) {
            running += numbers[j];  // sum of subarray [i..j]

            if (running <= first) { 
                second = first;
                first = running;
            } else if (running < second) {
                second = running;
            }
        }
    }
    return second;
}
