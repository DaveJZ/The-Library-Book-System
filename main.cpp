#include "Library.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n--- Library Menu ---\n";
    std::cout << "1. View all books\n";
    std::cout << "2. View all patrons\n";
    std::cout << "3. Check out book\n";
    std::cout << "4. Return book\n";
    std::cout << "5. Search books by author\n";
    std::cout << "6. Save and Exit\n";
    std::cout << "Select an option: ";
}

int main() {
    Library library;
    try {
        library.loadData();
    } catch (const std::exception& e) {
        std::cerr << "Startup Warning: " << e.what() << " (Creating empty library)\n";
    }

    int choice = 0;
    do {
        displayMenu();
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number (1-6).\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        try {
            if (choice == 1) {
                library.displayBooks();
            } else if (choice == 2) {
                library.displayPatrons();
            } else if (choice == 3) {
                int pid;
                std::cout << "Enter Patron ID: ";
                if (!(std::cin >> pid)) {
                    std::cout << "Invalid input. Returning to menu.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (!library.isValidPatron(pid)) {
                    std::cout << "Error - Patron ID " << pid << " not found. Returning to menu.\n";
                    continue;
                }

                //Show only available books
                library.displayAvailableBooks();

                std::string title;
                std::cout << "Enter Book Title: ";
                std::getline(std::cin, title);
                library.checkoutBook(pid, title);

                } else if (choice == 4) {
                // Show the list first
                library.displayBorrowedBooks();

                // If no books are out, jump back to menu
                if (library.getCheckedOutCount() == 0) {
                    continue; 
                }

                int pid;
                std::cout << "Enter Patron ID: ";
                if (!(std::cin >> pid)) {
                    std::cout << "Invalid input. Returning to menu.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (!library.isValidPatron(pid)) {
                    std::cout << "Error - Patron ID " << pid << " not found. Returning to menu.\n";
                    continue;
                }

                std::string title;
                std::cout << "Enter Book Title: ";
                std::getline(std::cin, title);
                library.returnBook(pid, title);
            
            } else if (choice == 5) {
                std::string author;
                std::cout << "What is the name of the author? ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, author);
                library.searchByAuthor(author);
            } else if (choice == 6) {
                library.saveData();
                std::cout << "Data saved to output files. Exiting...\n";
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Error - " << e.what() << "\n";
        }
    } while (choice != 6);

    return 0;
}