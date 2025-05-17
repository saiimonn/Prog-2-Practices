#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 50
#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[MAX_TITLE];
    int year;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} BookList;

// Function declarations
void addBook(BookList *list, Book b) {
    list->books[list->count] = b;
    list->count++;    
}

void removeBook(BookList *list, int id) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(list->books[i].id == id) {
            for(int j = i; j < list->count - 1; j++) {
                list->books[j] = list->books[j + 1];
            }
            list->count--;
            printf("Book with ID %d removed successfully\n", id);
            return;
        }
    }
    printf("Book with ID %d does not exist\n", id);
}

void updateBook(BookList *list, int id, const char *newTitle, int newYear) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(list->books[i].id == id) {
            strcpy(list->books[i].title, newTitle);
            list->books[i].year = newYear;
            printf("Book with ID %d updated successfully\n", id);
            return;
        }
    }
    printf("Book with ID %d does not exist\n", id);
}

void displayBooks(BookList list) {
    if(list.count == 0) {
        printf("List is empty\n");
        return;
    }

    printf("\nBook inventory:\n");
    for(int i = 0; i < list.count; i++) printf("Book ID: %d, Book Name: %s, Book Year: %d\n", list.books[i].id, list.books[i].title, list.books[i].year);
    printf("\n");
}

int main() {
    BookList library = {.count = 0};

    Book b1 = {1, "1984", 1949};
    Book b2 = {2, "To Kill a Mockingbird", 1960};
    Book b3 = {3, "The Great Gatsby", 1925};

    addBook(&library, b1);
    addBook(&library, b2);
    addBook(&library, b3);
    displayBooks(library);

    updateBook(&library, 2, "Mockingbird", 1961);
    removeBook(&library, 1);
    displayBooks(library);

    return 0;
}