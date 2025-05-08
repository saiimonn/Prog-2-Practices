#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} List;

void initList(List *list) {
    list->size = 0;
}

void displayList(List *list) {
    if(list->size == 0) {
        printf("List empty\n");
        return;
    }

    printf("List elements: ");
    for(int i = 0; i < list->size; i++) printf("%d ", list->data[i]);
    printf("\n");
}

void insertEnd(List *list, int val) {
    if(list->size >= MAX) {
        printf("List is full\n");
        return;
    }

    list->data[list->size] = val;
    list->size++;
}

void deleteFront(List *list) {
    if(list->size == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->size - 1; i++) list->data[i] = list->data[i + 1];
    list->size--;
}

int main() {
    List myList;
    initList(&myList);

    insertEnd(&myList, 44);
    insertEnd(&myList, 42);
    insertEnd(&myList, 26);
    insertEnd(&myList, 62);
    insertEnd(&myList, 35);
    insertEnd(&myList, 16);
    insertEnd(&myList, 65);
    insertEnd(&myList, 93);

    displayList(&myList);

    deleteFront(&myList);

    displayList(&myList);
}