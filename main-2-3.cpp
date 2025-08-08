
#include <iostream>
using namespace std;

bool is_palindrome(const int integers[], int length);
int  sum_array_elements(const int integers[], int length);
int  sum_if_palindrome(const int integers[], int length);

int main() {
    int a1[] = {1, 2, 2, 1}; 
    int a2[] = {1, 2, 3};

    cout << sum_if_palindrome(a1, 4) << "\n";
    cout << sum_if_palindrome(a2, 3) << "\n";

    return 0;
}
