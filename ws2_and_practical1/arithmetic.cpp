#include <iostream>
#include <string>
#include <bitset>

// Converts binary string to decimal I just use library thingy
int binary_Decimal(const std::string& bin) {
    return std::stoi(bin, nullptr, 2);
}

// this too
std::string decimal_Binary(int num) {
    return std::bitset<16>(num).to_string();
}// but it always return 16 digit idk how to cut it down :(


std::string binary_Add(const std::string& a, const std::string& b) {
    int result = binary_Decimal(a) + binary_Decimal(b);
    return decimal_Binary(result);
}
std::string binaryShiftLeft(const std::string& bin) {
    int result = binary_Decimal(bin) << 1;
    return decimal_Binary(result);
}

int main() {
    std::string bin1 = "111011101011";   // 3819 in decimal
    std::string bin2 = "11";             // 3 in decimal

    std::cout << "[Binary Addition: 3819 + 3]\n";
    std::string sum = binary_Add(bin1, bin2);
    std::cout << "Binary: " << sum << "\n";
    std::cout << "Decimal: " << binary_Decimal(sum) << "\n";

    std::cout << "\n[Left Shift: 3819 × 2]\n";
    std::string shifted = binaryShiftLeft(bin1);
    std::cout << "Binary: " << shifted << "\n";
    std::cout << "Decimal: " << binary_Decimal(shifted) << "\n";

    return 0;
}
