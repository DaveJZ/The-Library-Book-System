#ifndef PATRON_H
#define PATRON_H
#include "Book.h"
#include <vector>

class Patron {
    std::string name;
    int id;
    std::vector<Book*> borrowedBooks;
public:
    Patron(std::string n, int i);
    void borrowBook(Book* b);
    void returnBook(Book* b);
    void displayPatron() const;
    int getId() const { return id; }
    std::string getName() const { return name; }
    bool operator==(const Patron& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Patron& p);
};

#endif