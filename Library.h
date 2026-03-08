#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Patron.h"
#include "Transaction.h"
#include <vector>
#include <map>
#include <fstream>

// Template requirement for file saving operations
template <typename T>
void saveCollectionToFile(const std::vector<T>& collection, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) throw std::runtime_error("Failed to open file for saving: " + filename);
    for (const auto& item : collection) {
        file << item << "\n";
    }
}

class Library {
    std::vector<Book*> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;
    std::map<std::string, Book*> bookMap; // Map collection requirement

public:
    ~Library();
bool isValidPatron(int id) const;
    void loadData();
    void saveData();
    void addBook(Book* b);
    void addPatron(const Patron& p);
    void checkoutBook(int patronId, std::string title);
    void returnBook(int patronId, std::string title);
    void displayBooks() const;
    void displayPatrons() const;
    void searchByAuthor(const std::string& author) const;
    void searchByGenre(Genre g) const;
    void displayAvailableBooks() const;
    void displayBorrowedBooks() const;
    int getCheckedOutCount() const;
};

#endif