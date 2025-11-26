📚 Basic Library Management System in C — Description (Brief & Simple)
🔹 What is a Library Management System?

A Library Management System is a small computer program that helps store and manage book information.
In this project, you can:
🌟 UNIQUE FEATURES INCLUDED
⭐ 1. Password Login System

Prevents unauthorized access.

⭐ 2. File Handling

Books are saved in library.txt and loaded automatically.

⭐ 3. Search Book by ID

Makes locating books easy.

⭐ 4. Delete Book Feature

Removes a book and shifts all others.

⭐ 5. Update/Edit Book Details

Allows modifying book title and author.

⭐ 6. Duplicate ID Prevention

Avoids repeated book entries.

⭐ 7. Clean Table Display

Shows books in a neat formatted table.

⭐ 8. Professional, Real-world feel

Very impressive for school/college projects.

Add a new book

View all books

Search a book using its ID

Delete a book

The program stores all book records in a file called library.dat, so even after closing the program, the data is saved.

🔹 What libraries are used in C (Header Files)?
Header File	Purpose
#include <stdio.h>	Used for input/output functions like printf(), scanf(), fopen(), fwrite(), fread()
#include <stdlib.h>	Used for functions like exit(), remove(), rename()
#include <string.h>	Used for string handling like copying and comparing text

These are the only libraries needed for this basic project.

🔹 What functions are used (Brief Explanation)
📌 1. addBook()

Takes book details from user (ID, title, author)

Saves the book to library.dat using file handling

📌 2. viewBooks()

Reads all books from the file

Displays each book’s ID, title, and author

📌 3. searchBook()

Searches for a specific book using its ID

If found → displays the book

If not → shows “Book not found”

📌 4. deleteBook()

Removes a book from the file

Uses a temporary file to rewrite data without the deleted book

📌 5. main()

Runs the menu

Lets the user choose options (Add, View, Search, Delete, Exit)

🔹 File Handling Functions Used

These functions help save/read data:

Function	Purpose
fopen()	Open file for reading/writing
fwrite()	Save book record to file
fread()	Read book records from file
fclose()	Close file
remove()	Delete a file
rename()	Rename temporary file → library file
🔹 Structure Used

The project uses a struct to store book data:

struct Book {
    int id;
    char title[50];
    char author[50];
};


It groups all book information together.

✔️ Short 4–Line Description (for your report)
This project is a simple Library Management System created in C language.  
It uses structures and file handling to store book information such as ID, title, and author.  



OUTPUT:

PS C:\Users\rajal\OneDrive\Desktop\project> cd 'c:\Users\rajal\OneDrive\Desktop\project\output'
PS C:\Users\rajal\OneDrive\Desktop\project\output> & .\'libarysystem.exe'

====== Library Management System ======
1. Add Book
2. View All Books
3. Search Book by ID
4. Delete Book
5. Exit
Enter your choice: 1
Enter Book ID: 234
Enter Book Title: FLORA
Enter Author Name: ASHISH KUMAR
Book added successfully!

====== Library Management System ======
1. Add Book
2. View All Books
3. Search Book by ID
4. Delete Book
5. Exit
Enter your choice: 2

--- Book List ---

ID: 28390
Title: asbjjdjhd
Author: asshli inshan

ID: 234
Title: FLORA
Author: ASHISH KUMAR

====== Library Management System ======
1. Add Book
2. View All Books
3. Search Book by ID
4. Delete Book
5. Exit
Enter your choice: 1
Enter Book ID: 28390
Enter Book Title: ANBBHJ
Enter Author Name: SJHUU
Book added successfully!

====== Library Management System ======
1. Add Book
2. View All Books
3. Search Book by ID
4. Delete Book
5. Exit
Enter your choice: 4
Enter Book ID to delete: 234
Book deleted successfully!

====== Library Management System ======
1. Add Book
2. View All Books
3. Search Book by ID
4. Delete Book
5. Exit
Enter your choice:

![WhatsApp Image 2025-11-26 at 10 44 56](https://github.com/user-attachments/assets/4205913e-5280-4534-96ad-764b2d72759f)

![WhatsApp Image 2025-11-26 at 10 44 57](https://github.com/user-attachments/assets/83ae20ef-f6aa-44b7-a0fc-f784769a94a4)



The user can add, view, search, and delete books from the system.  
The program uses standard C libraries like stdio.h, stdlib.h, and string.h.
