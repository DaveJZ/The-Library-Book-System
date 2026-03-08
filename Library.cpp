#include "Library.h"
#include "Date.h"
#include <sstream>

Library::~Library() {
    for (Book* b : books) {
        delete b;
    }
}

void Library::loadData() {
    std::ifstream bFile("Books.txt");
    if (!bFile) throw std::runtime_error("Failed to open books file.");
    std::string line;
    while (std::getline(bFile, line)) {
        if(line.empty()) continue;
        std::stringstream ss(line);
        std::string genreStr, title, author, type, extra;
        std::getline(ss, genreStr, ',');
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, type, ',');
        std::getline(ss, extra, ',');
        
        Genre g = stringToGenre(genreStr);
        Book* newBook = nullptr;
        if (type == "Printed") {
            newBook = new PrintedBook(title, author, g, std::stoi(extra));
        } else {
            newBook = new EBook(title, author, g, std::stod(extra));
        }
        addBook(newBook);
    }

    std::ifstream pFile("Patrons.txt");
    if (!pFile) throw std::runtime_error("Failed to open patrons file.");
    while (std::getline(pFile, line)) {
        if(line.empty()) continue;
        std::stringstream ss(line);
        std::string idStr, name;
        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        addPatron(Patron(name, std::stoi(idStr)));
    }
}

void Library::saveData() {
    saveCollectionToFile(patrons, "Patrons_out.txt");
    saveCollectionToFile(transactions, "Transactions_out.txt");
    std::ofstream file("Books_out.txt");
    for (const auto& b : books) {
        file << genreToString(b->getGenre()) << "," << b->getTitle() << "," << b->getAuthor() << "\n";
    }
}

bool Library::isValidPatron(int id) const {
    for (const auto& p : patrons) {
        if (p.getId() == id) return true;
    }
    return false;
}

void Library::addBook(Book* b) {
    books.push_back(b);
    bookMap[b->getTitle()] = b;
}

void Library::addPatron(const Patron& p) {
    patrons.push_back(p);
}

void Library::displayAvailableBooks() const {
    std::cout << "\n--- Available Books ---\n";
    for (const auto& b : books) {
        if (b->getStatus() == BookStatus::Available) {
            b->displayInfo();
        }
    }
    std::cout << "-----------------------\n";
}

void Library::checkoutBook(int patronId, std::string title) {
    if (bookMap.find(title) == bookMap.end()) {
        throw std::invalid_argument("Book not found in library.");
    }
    Book* b = bookMap[title];
    
    // NEW: Check if the book is already checked out
    if (b->getStatus() == BookStatus::CheckedOut) {
        throw std::invalid_argument("This book is already checked out by a patron.");
    }
    
    Patron* targetPatron = nullptr;
    for (auto& p : patrons) {
        if (p.getId() == patronId) {
            targetPatron = &p;
            break;
        }
    }
    
    if (!targetPatron) throw std::invalid_argument("Patron ID not found.");
    
    targetPatron->borrowBook(b);
    std::string dateStr = Date::getCurrentDate();
    transactions.push_back(Transaction(patronId, title, dateStr));
    std::cout << "Success! Due date is: " << Date::getDueDate(14) << "\n";
}

void Library::returnBook(int patronId, std::string title) {
    if (bookMap.find(title) == bookMap.end()) throw std::invalid_argument("Book not found.");
    Book* b = bookMap[title];
    
    for (auto& p : patrons) {
        if (p.getId() == patronId) {
            p.returnBook(b);
            std::cout << "Book returned successfully.\n";
            return;
        }
    }
    throw std::invalid_argument("Patron ID not found.");
}

void Library::displayBooks() const {
    for (const auto& b : books) b->displayInfo();
}

void Library::displayPatrons() const {
    for (const auto& p : patrons) p.displayPatron();
}

void Library::searchByAuthor(const std::string& author) const {
    bool found = false;
    for (const auto& b : books) {
        if (b->getAuthor() == author) {
            b->displayInfo();
            found = true;
        }
    }
    if (!found) {
        std::cout << "This name is not in the library.\n";
    }
}

void Library::searchByGenre(Genre g) const {
    for (const auto& b : books) {
        if (b->getGenre() == g) b->displayInfo();
    }
}

void Library::displayBorrowedBooks() const {
    int count = 0;
    std::cout << "\n--- Books Currently Checked Out ---\n";
    for (const auto& b : books) {
        if (b->getStatus() == BookStatus::CheckedOut) {
            b->displayInfo();
            count++;
        }
    }

    if (count == 0) {
        std::cout << "There is no books that are checked out.\n";
    }
    std::cout << "-----------------------------------\n";
}

int Library::getCheckedOutCount() const {
    int count = 0;
    for (const auto& b : books) {
        if (b->getStatus() == BookStatus::CheckedOut) count++;
    }
    return count;
}