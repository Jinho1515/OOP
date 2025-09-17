// InvoiceTest.h

#include <iostream>
#include "Invoice.h"

class InvoiceTest {
public:
    void runTests() {
        testAddServiceCost();
        testConstructor();
        testGetters();
        testNonPositiveInputs();
        testMultipleAdds();
        // Add other test methods here if needed
    }

private:
    void testAddServiceCost() {
        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(10);
            if (invoice.getDollarsOwed() != 10) {
                std::cout << "Test 1 failed!" << std::endl;
            }
        }

        {
            Invoice invoice("ABCD");
            invoice.addServiceCost(1);
            if (invoice.getDollarsOwed() != 1) {
                std::cout << "Test 2 failed!" << std::endl;
            }
        }

        // Add more test cases here
    }

    void testConstructor() {
        {
            Invoice invoice("INV-001");
            if (invoice.getInvoiceId() != "INV-001") {
                std::cout << "Test 3 failed!" << std::endl; // ctor sets ID
            }
            if (invoice.getDollarsOwed() != 0) {
                std::cout << "Test 4 failed!" << std::endl; // ctor starts at 0
            }
        }
    }

    void testGetters() {
        {
            Invoice invoice("XYZ");
            if (invoice.getInvoiceId() != "XYZ") {
                std::cout << "Test 5 failed!" << std::endl;
            }
            if (invoice.getDollarsOwed() != 0) {
                std::cout << "Test 6 failed!" << std::endl;
            }
            invoice.addServiceCost(7);
            if (invoice.getDollarsOwed() != 7) {
                std::cout << "Test 7 failed!" << std::endl;
            }
        }
    }

    void testNonPositiveInputs() {
        {
            Invoice invoice("A1");
            invoice.addServiceCost(0);
            if (invoice.getDollarsOwed() != 0) {
                std::cout << "Test 8 failed!" << std::endl; // zero ignored
            }
            invoice.addServiceCost(-5);
            if (invoice.getDollarsOwed() != 0) {
                std::cout << "Test 9 failed!" << std::endl; // negative ignored
            }
        }
    }

    void testMultipleAdds() {
        {
            Invoice invoice("RUN");
            invoice.addServiceCost(2);
            invoice.addServiceCost(3);
            invoice.addServiceCost(4);
            if (invoice.getDollarsOwed() != 9) {
                std::cout << "Test 10 failed!" << std::endl; // 2+3+4
            }
        }
    }

    // Add other test functions here
};
