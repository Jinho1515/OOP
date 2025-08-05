#include <iostream>
#include <string>

std::string convertToBinary(int number) {
    if (number == 0) 
    return "0";
    std::string binary = "";
    while (number > 0) {
        binary = std::to_string(number % 2) + binary;
        number = number / 2;
    }
    return binary;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::string result = convertToBinary(num);
    std::cout << "Binary: " << result << std::endl;
    return 0;
}
