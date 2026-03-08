#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction {
    int patronId;
    std::string bookTitle;
    std::string date;
public:
    Transaction(int pid, std::string bt, std::string d);
    void displayTransaction() const;
    friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
};

#endif