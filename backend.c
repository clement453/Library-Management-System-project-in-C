#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"

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
        printf("Library is full!\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &books[bookCount].id);
    getchar(); // Clear newline from buffer
    printf("Enter book title: ");
    fgets(books[bookCount].title, sizeof(books[bookCount].title), stdin);
    printf("Enter author name: ");
    fgets(books[bookCount].author, sizeof(books[bookCount].author), stdin);
    books[bookCount].isIssued = 0;
    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    printf("\n=== Book List ===\n");
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
    getchar();
    printf("Enter book title to search: ");
    fgets(search, sizeof(search), stdin);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, search)) {
            printf("Found: ID %d | Title: %sAuthor: %s\n",
                books[i].id, books[i].title, books[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("No book found with that title.\n");
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
            printf("Book deleted successfully.\n");
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
                printf("Book is already issued.\n");
            } else {
                books[i].isIssued = 1;
                printf("Book issued successfully.\n");
            }
            return;
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
            } else {
                books[i].isIssued = 0;
                printf("Book returned successfully.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}
