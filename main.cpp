#include "UnitTest.h"
#include "EquivalenceTests.h"

int main() {
    UnitTest unitTest;
    unitTest.runTests();

    EquivalenceTests equivalenceTests;
    equivalenceTests.runTests();

    return 0;
}
