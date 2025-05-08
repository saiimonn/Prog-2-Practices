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

void insertEnd(List *list, int val) {
    if(list->size >= MAX) {
        printf("List is full\n");
        return;
    }

    list->data[list->size] = val;
    list->size++;
}

void deleteAtIndex(List *list, int idx) {
    if(idx < 0 || idx > list->size) {
        printf("Invalid index\n");
        return;
    } else if (list->size == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = idx; i < list->size - 1; i++) list->data[i] = list->data[i + 1];
    list->size--;
}

int main() {
    List myList;
    initList(&myList);

    insertEnd(&myList, 42);
    insertEnd(&myList, 75);
    insertEnd(&myList, 84);
    insertEnd(&myList, 18);
    insertEnd(&myList, 29);
    insertEnd(&myList, 74);
    insertEnd(&myList, 47);

    displayList(&myList);

    int idx;
    printf("Enter index to delete: ");
    scanf("%d", &idx);
    deleteAtIndex(&myList, idx);

    displayList(&myList);
}