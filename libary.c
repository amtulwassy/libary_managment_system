#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100

// Structure for Book
struct Book {
    int id;
    char title[50];
    char author[50];
};

// Global variables
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void loadBooks();
void saveBooks();
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void updateBook();
int login();

int main() {
    int choice;

    if (!login()) {
        printf("\nAccess Denied!\n");
        return 0;
    }

    loadBooks();

    while (1) {
        printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Update Book\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: updateBook(); break;
            case 6: saveBooks(); printf("\nData Saved. Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}


// ==================== LOGIN FUNCTION ====================
int login() {
    char password[20];
    char correctPass[] = "admin123";

    printf("Enter Password to access system: ");
    scanf("%s", password);

    if (strcmp(password, correctPass) == 0)
        return 1;
    else
        return 0;
}


// ==================== LOAD BOOKS FROM FILE ====================
void loadBooks() {
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL) return;  // No file exists yet

    while (fscanf(fp, "%d,%49[^,],%49[^\n]\n",
                  &library[bookCount].id,
                  library[bookCount].title,
                  library[bookCount].author) != EOF) {
        bookCount++;
    }
    fclose(fp);
}


// ==================== SAVE BOOKS TO FILE ====================
void saveBooks() {
    FILE *fp = fopen("library.txt", "w");

    for (int i = 0; i < bookCount; i++) {
        fprintf(fp, "%d,%s,%s\n",
                library[i].id,
                library[i].title,
                library[i].author);
    }
    fclose(fp);
}


// ==================== ADD BOOK ====================
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }

    int id;
    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    // Check duplicate ID
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("\nError: Book ID already exists!\n");
            return;
        }
    }

    library[bookCount].id = id;

    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[bookCount].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[bookCount].author);

    bookCount++;
    printf("\nBook Added Successfully!\n");
}


// ==================== DISPLAY BOOKS ====================
void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books in library.\n");
        return;
    }

    printf("\n---------------------------------------------------------------\n");
    printf(" ID    |           Title                    |     Author\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf(" %-5d | %-30s | %-20s\n",
               library[i].id,
               library[i].title,
               library[i].author);
    }
}


// ==================== SEARCH BOOK ====================
void searchBook() {
    int id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n",
                   library[i].id,
                   library[i].title,
                   library[i].author);
            return;
        }
    }
    printf("\nBook Not Found!\n");
}


// ==================== DELETE BOOK ====================
void deleteBook() {
    int id;
    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];  // Shift records
            }
            bookCount--;
            printf("\nBook Deleted Successfully!\n");
            return;
        }
    }
    printf("\nBook Not Found!\n");
}


// ==================== UPDATE BOOK ====================
void updateBook() {
    int id;
    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("\nEnter new Title: ");
            scanf(" %[^\n]", library[i].title);

            printf("Enter new Author: ");
            scanf(" %[^\n]", library[i].author);

            printf("\nBook Updated Successfully!\n");
            return;
        }
    }
    printf("\nBook Not Found!\n");
}
