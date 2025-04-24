

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
