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

void displayList(List *list) {
    if(list->size == 0) {
        printf("Empty list.\n");
        return;
    }

    printf("Elements: ");
    for(int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void insert(List *list, int index, int value) {
    if(list->size == MAX) {
        printf("List full\n");
        return;
    } else if(index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }

    for(int i = list->size; i > index; i--) { //shifting elements to the right
        list->data[i] = list->data[i - 1];
    }

    list->data[index] = value;
    list->size++;
}

int main() {
    List myList;
    initializeList(&myList);

    insert(&myList, 0, 10);
    insert(&myList, 1, 20);
    insert(&myList, 1, 30);

    displayList(&myList);
}