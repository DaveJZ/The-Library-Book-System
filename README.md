Inputs: The application accepts user menu choices, patron IDs, book titles, and author names. It loads starting data from Books.txt and Patrons.txt.
Outputs: The console displays book lists, patron lists, due dates, and error messages. The system saves state to output text files on exit.

START
Initialize Library system
Try loading data from files WHILE user choice is not "Save and Exit"     Display menu 
    Get choice
    IF choice is 1: Display books     IF choice is 2: Display patrons     IF choice is 3: Get ID and title, checkout book     IF choice is 4: Get ID and title, return book     IF choice is 5: Get author name, search books     Catch and show errors (missing books, bad IDs) 
END WHILE
Save library data to files 
END

