#include "Book.h"

Book::Book(std::string t, std::string a, Genre g) : title(t), author(a), genre(g), status(BookStatus::Available) {}

void Book::displayInfo() const {
    std::cout << "Title: " << title << ", Author: " << author 
              << ", Genre: " << genreToString(genre) 
              << ", Status: " << statusToString(status) << "\n";
}

void Book::setStatus(BookStatus s) { status = s; }
BookStatus Book::getStatus() const { return status; }

bool Book::operator==(const Book& other) const {
    return title == other.title && author == other.author;
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << b.title << " by " << b.author;
    return os;
}

EBook::EBook(std::string t, std::string a, Genre g, double size) : Book(t, a, g), fileSizeMB(size) {}

void EBook::displayInfo() const {
    Book::displayInfo();
    std::cout << "   [EBook] Size: " << fileSizeMB << " MB\n";
}

PrintedBook::PrintedBook(std::string t, std::string a, Genre g, int pages) : Book(t, a, g), pageCount(pages) {}

void PrintedBook::displayInfo() const {
    Book::displayInfo();
    std::cout << "   [Printed] Pages: " << pageCount << "\n";
}