#ifndef INVOICE_H
#define INVOICE_H

#include <string>

class Invoice {
public:
    // Constructor that initializes an invoice with a given invoice ID.
    explicit Invoice(const std::string& invoiceId);

    // Adds the cost of a service to the current invoice in dollars.
    // Accepts only positive dollar amounts.
    void addServiceCost(int costDollars);

    // Returns the total amount owed in dollars for the services on the invoice.
    int getDollarsOwed() const;

    // Returns the unique identifier (ID) for the invoice.
    std::string getInvoiceId() const;

private:
    std::string invoiceId;
    int dollarsOwed;
};

#endif // INVOICE_H
