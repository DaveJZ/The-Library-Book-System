#include "Transaction.h"
#include <iostream>

Transaction::Transaction(int pid, std::string bt, std::string d) 
    : patronId(pid), bookTitle(bt), date(d) {}

void Transaction::displayTransaction() const {
    std::cout << "Date: " << date << " | Patron ID: " << patronId << " | Book: " << bookTitle << "\n";
}

std::ostream& operator<<(std::ostream& os, const Transaction& t) {
    os << t.date << "," << t.patronId << "," << t.bookTitle;
    return os;
}