#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} List;

void initializeList(List *list) {
    list->size = 0;
}

void insertAtEnd(List *list, int val) {
    if(list->size == MAX) {
        printf("List is full\n");
        return;
    }

    list->data[list->size] = val;
    list->size++;
}