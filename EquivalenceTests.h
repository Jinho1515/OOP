// EquivalenceTests.h

#include <iostream>
#include <string>
#include <limits>
#include "Addition.h"

class EquivalenceTests {
public:
    void runTests() {
        std::cout << "Running Equivalence Class tests...\n";
        testPositiveIntegers();
        testNegativeIntegers();
        testMixedSigns();
        testZeroes();
        testBigPositiveNumbers();
        testBigNegativeNumbers();
        testSpecialOnes();

        std::cout << "\n---- Summary (Equivalence) ----\n"
                  << "Total: " << total_ << ", Passed: " << (total_ - fails_)
                  << ", Failed: " << fails_ << std::endl;
        if (fails_ == 0) {
            std::cout << "ALL EQUIVALENCE TESTS PASSED \n";
        } else {
            std::cout << "SOME EQUIVALENCE TESTS FAILED \n";
        }
    }

private:
    int total_ = 0;
    int fails_ = 0;

    void expectEqual(int actual, int expected, const std::string& name) {
        ++total_;
        if (actual != expected) {
            ++fails_;
            std::cout << "[FAIL] " << name
                      << " | expected: " << expected
                      << ", got: " << actual << '\n';
        } else {
            std::cout << "[PASS] " << name << '\n';
        }
    }

    // --- Equivalence Classes ---

    // Positive integers
    void testPositiveIntegers() {
        Addition add;
        expectEqual(add.add(5, 10), 15, "positive: 5 + 10");
        expectEqual(add.add(1, 1), 2, "positive: 1 + 1");
    }

    // Negative integers
    void testNegativeIntegers() {
        Addition add;
        expectEqual(add.add(-4, -5), -9, "negative: -4 + -5");
        expectEqual(add.add(-1, -1), -2, "negative: -1 + -1");
    }

    // Mixtures of positive and negative
    void testMixedSigns() {
        Addition add;
        expectEqual(add.add(7, -3), 4, "mixed: 7 + -3");
        expectEqual(add.add(-8, 2), -6, "mixed: -8 + 2");
        expectEqual(add.add(100, -100), 0, "mixed: 100 + -100");
    }

    // Zeroes
    void testZeroes() {
        Addition add;
        expectEqual(add.add(0, 0), 0, "zero: 0 + 0");
        expectEqual(add.add(0, 9), 9, "zero: 0 + 9");
        expectEqual(add.add(-11, 0), -11, "zero: -11 + 0");
    }

    // Big positive numbers (keep within int range to avoid overflow)
    void testBigPositiveNumbers() {
        Addition add;
        expectEqual(add.add(1'000'000, 2'000'000), 3'000'000, "big+: 1e6 + 2e6");
        expectEqual(add.add(1'500'000'000, 500'000'000), 2'000'000'000, "big+: 1.5e9 + 0.5e9");
    }

    // Big negative numbers (still within int range)
    void testBigNegativeNumbers() {
        Addition add;
        expectEqual(add.add(-1'000'000, -2'000'000), -3'000'000, "big-: -1e6 + -2e6");
        expectEqual(add.add(-1'200'000'000, -700'000'000), -1'900'000'000, "big-: -1.2e9 + -0.7e9");
    }

    // Special cases: 1 and -1
    void testSpecialOnes() {
        Addition add;
        expectEqual(add.add(1, 99), 100, "special: 1 + 99");
        expectEqual(add.add(-1, 99), 98, "special: -1 + 99");
        expectEqual(add.add(1, -1), 0, "special: 1 + -1");
        expectEqual(add.add(-1, -1), -2, "special: -1 + -1 (dup class check)");
    }
};
