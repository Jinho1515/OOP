// UnitTest.h

#include <iostream>
#include <string>
#include "Addition.h"

class UnitTest {
public:
    void runTests() {
        testAddition();
        std::cout << "\n---- Summary ----\n"
                  << "Total: " << total_ << ", Passed: " << (total_ - fails_) 
                  << ", Failed: " << fails_ << std::endl;
        if (fails_ == 0) {
            std::cout << "ALL TESTS PASSED " << std::endl;
        } else {
            std::cout << "SOME TESTS FAILED " << std::endl;
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
                      << ", got: " << actual << std::endl;
        } else {
            std::cout << "[PASS] " << name << std::endl;
        }
    }

    void testAddition() {
        std::cout << "Running Addition tests...\n";
        Addition addition;

        // Three required tests (and a couple more for practice)
        expectEqual(addition.add(1, 2), 3, "1 + 2 = 3");
        expectEqual(addition.add(-5, 5), 0, "-5 + 5 = 0");
        expectEqual(addition.add(0, 0), 0, "0 + 0 = 0");

        // Extra
        expectEqual(addition.add(-3, -7), -10, "-3 + (-7) = -10");
        expectEqual(addition.add(1000000, 2000000), 3000000, "1e6 + 2e6 = 3e6");
    }
};
