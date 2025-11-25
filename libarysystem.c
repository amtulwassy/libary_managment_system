#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Book
struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook();
void viewBooks();
void searchBook();
void deleteBook();

int main() {
    int choice;

    while (1) {
        printf("\n====== Library Management System ======\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addBook() {
    struct Book b;
    FILE *fp = fopen("library.dat", "ab");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title: ");
    getchar();
    gets(b.title);
    printf("Enter Author Name: ");
    gets(b.author);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void viewBooks() {
    struct Book b;
    FILE *fp = fopen("library.dat", "rb");

    if (!fp) {
        printf("No books found!\n");
        return;
    }

    printf("\n--- Book List ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\n", b.id, b.title, b.author);
    }

    fclose(fp);
}

void searchBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("No books found!\n");
        return;
    }

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", b.id, b.title, b.author);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Book not found!\n");

    fclose(fp);
}

void deleteBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp) {
        printf("No books available to delete!\n");
        return;
    }

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id != id) {
            fwrite(&b, sizeof(b), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (found)
        printf("Book deleted successfully!\n");
    else
        printf("Book not found!\n");
}
