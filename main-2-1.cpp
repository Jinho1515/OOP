#include <iostream>
#include <string>
using namespace std;

void print_binary_str(string decimal_number);

int main() {
    string input;

    // Example test
    input = "13";
    print_binary_str(input); 

    input = "5";
    print_binary_str(input); 

    return 0;
}
