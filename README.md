#The Library Book System
This C++ program manages library books, patrons, and checkouts. 

Features
View all books in the library.
View registered patrons.
Check out books to patrons.
Return borrowed books.
Search for books by the author's name.
Automatically calculate due dates.

Inputs and Outputs
Inputs: Accepts menu choices, patron IDs, book titles, and author names from the user. It loads starting inventory and patron data from Books.txt and Patrons.txt.
Outputs: Displays book lists, patron lists, transaction due dates, and error messages. The system saves the final state to output text files (Books_out.txt, Patrons_out.txt, Transactions_out.txt) when you exit.

Project Structure
main.cpp: The main menu loop and user interface.
Library.h / Library.cpp: Manages the collections of books, patrons, and transactions.
Book.h / Book.cpp: The base class for books, plus derived classes for EBook and PrintedBook.
Patron.h / Patron.cpp: Manages patron details and their borrowed books.
Transaction.h / Transaction.cpp: Tracks checkout records.
Date.h / Date.cpp: Handles current dates and due date math.
Globals.h: Holds shared enums and helper functions.

How to Run
1.Put all the .cpp and .h files into one folder.
2.Use the default text or change it in Books.txt and Patrons.txt in that same folder.
3.Open your terminal or command prompt.
4.Compile the code using a C++ compiler
