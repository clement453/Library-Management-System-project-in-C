#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100



typedef struct {
    int id;
    char title[100];
    char author[50];
    int isIssued; // 0 = available, 1 = issued
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library full!\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &books[bookCount].id);
    printf("Enter book title: ");
    getchar(); // clear newline
    fgets(books[bookCount].title, 100, stdin);
    printf("Enter author name: ");
    fgets(books[bookCount].author, 50, stdin);
    books[bookCount].isIssued = 0;
    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    printf("=== Book List ===\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %sAuthor: %sStatus: %s\n",
            books[i].id,
            books[i].title,
            books[i].author,
            books[i].isIssued ? "Issued\n" : "Available\n");
    }
}

void searchBook() {
    char search[100];
    printf("Enter book title to search: ");
    getchar();
    fgets(search, 100, stdin);
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, search)) {
            printf("Found: ID %d | Title: %sAuthor: %s\n", books[i].id, books[i].title, books[i].author);
        }
    }
}

void deleteBook() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book deleted.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued) {
                printf("Book already issued.\n");
                return;
            } else {
                books[i].isIssued = 1;
                printf("Book issued.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (!books[i].isIssued) {
                printf("Book was not issued.\n");
                return;
            } else {
                books[i].isIssued = 0;
                printf("Book returned.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Issue Book\n");
        printf("6. Return Book\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
