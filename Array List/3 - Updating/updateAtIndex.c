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

void updateAtIndex(List *list, int idx) {
    if(idx > MAX || idx > list->size) {
        printf("Invalid index\n");
        return;
    }
    int val;
    printf("Enter new value of index %d: ", idx);
    scanf("%d", &val);

    for(int i = 0; i < list->size; i++) {
        if(i == idx){
            list->data[i] = val;
            return;
        } 
    }
}

int main() {
    List myList;
    initList(&myList);

    insertEnd(&myList, 85);
    insertEnd(&myList, 27);
    insertEnd(&myList, 73);
    insertEnd(&myList, 94);
    insertEnd(&myList, 19);
    insertEnd(&myList, 94);
    insertEnd(&myList, 28);
    insertEnd(&myList, 59);

    displayList(&myList);

    int idx;
    printf("Enter index to update: ");
    scanf("%d", &idx);

    updateAtIndex(&myList, idx);

    displayList(&myList);
}