#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char title[50];
    int pages;
} Book;

typedef struct {
    Book books[MAX];
    int count;
} BookCatalog;

void insertBookAt(BookCatalog *cat, char title[], int pages, int pos) {
    // Your code here
    if(cat->count >= MAX) {
        printf("Book inventory has reached maximum capacity\n");
        return;
    }

    Book newBook;
    strcpy(newBook.title, title);
    newBook.pages = pages;

    for(int i = cat->count; i > pos; i--) {
        cat->books[i] = cat->books[i - 1];
    }

    cat->books[pos] = newBook;
    cat->count++;
}

void showBooks(BookCatalog cat) {
    // Your code here
    if(cat.count == 0) {
        printf("No books available\n");
        return;
    }

    for(int i = 0; i < cat.count; i++) printf("[%d] Title: %s | Pages: %d\n", i, cat.books[i].title, cat.books[i].pages);
    printf("\n");
}

int main() {
    BookCatalog cat = {.count = 0};

    insertBookAt(&cat, "1984", 328, 0);
    insertBookAt(&cat, "LOTR", 900, 1);
    insertBookAt(&cat, "Dune", 412, 0);

    showBooks(cat);

    return 0;
}

/*
Books:
[0] Title: Dune | Pages: 412
[1] Title: 1984 | Pages: 328
[2] Title: LOTR | Pages: 900
*/