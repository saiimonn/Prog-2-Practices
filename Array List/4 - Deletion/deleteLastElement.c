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
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    for(int i = 0; i < list->size; i++) printf("%d ", list->data[i]);
    printf("\n");
}

void insertEnd(List *list, int value) {
    if(list->size >= MAX) {
        printf("List is full\n");
        return;
    }

    list->data[list->size] = value;
    list->size++;
}

void deleteEnd(List *list) {
    list->size--;
}

int main() {
    List myList;
    initList(&myList);

    insertEnd(&myList, 50);
    insertEnd(&myList, 482);
    insertEnd(&myList, 174);
    insertEnd(&myList, 249);
    insertEnd(&myList, 859);
    insertEnd(&myList, 46);
    insertEnd(&myList, 13);

    displayList(&myList);

    deleteEnd(&myList);

    displayList(&myList);
}