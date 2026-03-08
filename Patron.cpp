#include "Patron.h"
#include <algorithm>
#include <stdexcept>

Patron::Patron(std::string n, int i) : name(n), id(i) {}

void Patron::borrowBook(Book* b) {
    if (b->getStatus() == BookStatus::CheckedOut) {
        throw std::runtime_error("Book is already checked out.");
    }
    borrowedBooks.push_back(b);
    b->setStatus(BookStatus::CheckedOut);
}

void Patron::returnBook(Book* b) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), b);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        b->setStatus(BookStatus::Available);
    } else {
        throw std::invalid_argument("Patron does not have this book.");
    }
}

void Patron::displayPatron() const {
    std::cout << "Patron ID: " << id << ", Name: " << name << "\n";
    std::cout << "Borrowed Books: " << borrowedBooks.size() << "\n";
}

bool Patron::operator==(const Patron& other) const {
    return id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Patron& p) {
    os << p.id << "," << p.name;
    return os;
}