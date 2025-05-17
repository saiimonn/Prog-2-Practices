#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 20
typedef enum { AVAILABLE, BORROWED } BookStatus;

typedef struct {
    char title[50];
    char author[50];
    int year;
    BookStatus status;
} Book;

typedef struct bookNode {
    Book data;
    struct bookNode *next;
} *BookList;

typedef struct {
    Book books[MAX_BOOKS];  // Original array of books
    BookList availableList; // Linked list for AVAILABLE books
    int totalBooks;
} Library;

void initialize(Library *lib) {
    lib->totalBooks = 6; // You can adjust this value
    lib->availableList = NULL;

    Book sampleBooks[] = {
        {"The C Programming Language", "Kernighan & Ritchie", 1978, AVAILABLE},
        {"Clean Code", "Robert C. Martin", 2008, BORROWED},
        {"Introduction to Algorithms", "CLRS", 2009, AVAILABLE},
        {"Design Patterns", "Erich Gamma", 1994, BORROWED},
        {"The Pragmatic Programmer", "Andrew Hunt", 1999, AVAILABLE},
        {"Computer Networks", "Andrew S. Tanenbaum", 2010, BORROWED}
    };

    memcpy(lib->books, sampleBooks, lib->totalBooks * sizeof(Book));
}  // Preloads books into the array

void populateAvailableBooks(Library *lib) {
    for(int i = 0; i < lib->totalBooks; i++) {
        BookList newNode = malloc(sizeof(struct bookNode));
        if(!newNode) exit(0);

        if(lib->books[i].status == AVAILABLE) {
            newNode->data = lib->books[i];
            newNode->next = lib->availableList;
            lib->availableList = newNode;
        }
    }
    printf("Available books successfully transferred to linked list\n");
} // Transfer to LL

Book *getBorrowedBooks(Library *lib, int *count) {
    if(lib->totalBooks == 0) {
        printf("Library is empty\n");
        return NULL;
    }

    for(int i = 0; i < lib->totalBooks; i++) {
        if(lib->books[i].status == BORROWED) {
            (*count)++;
        }
    }

    if(*count == 0) {
        printf("There are no borrowed books\n");
        return NULL;
    }

    Book *borrowedBooks = malloc((*count) * sizeof(Book));
    if(!borrowedBooks) exit(0);

    int idx = 0;
    for(int i = 0; i < lib->totalBooks; i++) {
        if(lib->books[i].status == BORROWED) {
            borrowedBooks[idx++] = lib->books[i];
        }
    }
    return borrowedBooks;
} // Transfer to dyn. array

void displayAvailableBooks(BookList head) {
    if (!head) {
        printf("No books available\n");
        return;
    }

    printf("AVAILABLE BOOKS:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-30s %-20s %-6s %-10s\n", "TITLE", "AUTHOR", "YEAR", "STATUS");

    for (BookList ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%-30s %-20s %-6d %-10s\n",
               ptr->data.title,
               ptr->data.author,
               ptr->data.year,
               ptr->data.status == AVAILABLE ? "AVAILABLE" : "BORROWED");
    }
    printf("\n");
} // LL display

void displayBorrowedBooks(Book data[], int count) {
    if (count == 0) {
        printf("No borrowed books in list\n");
        return;
    }

    printf("BORROWED BOOKS:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-30s %-20s %-6s %-10s\n", "TITLE", "AUTHOR", "YEAR", "STATUS");

    for (int i = 0; i < count; i++) {
        printf("%-30s %-20s %-6d %-10s\n",
               data[i].title,
               data[i].author,
               data[i].year,
               data[i].status == BORROWED ? "BORROWED" : "AVAILABLE");
    }
    printf("\n");
} // Array display

int main() {
    Library lib;
    initialize(&lib);

    populateAvailableBooks(&lib);

    int borrowedCount = 0;
    Book *borrowed = getBorrowedBooks(&lib, &borrowedCount);

    printf("\n");
    displayBorrowedBooks(borrowed, borrowedCount);

    printf("\n");
    displayAvailableBooks(lib.availableList);

    free(borrowed); // Free dynamically allocated memory
    return 0;
}