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

void insert(List *list, int idx, int val) {
    if(list->size >= MAX) {
        printf("List is full\n");
        return;
    } else if(idx < 0 || idx > list->size) {
        printf("Invalid index\n");
        return;
    }

    for(int i = list->size; i > idx; i--) list->data[i] = list->data[i - 1];

    list->data[idx] = val;
    list->size++;
}

int searchValue(List *list, int val) {
    if(list->size == 0) {
        printf("List is empty!\n");
        return -1;
    }

    for(int i = 0; i < list->size; i++) {
        if(list->data[i] == val) return i;
    }

    return -1;
}

int main() {
    List myList;
    initList(&myList);

    insert(&myList, 0, 446);
    insert(&myList, 0, 426);
    insert(&myList, 0, 574);
    insert(&myList, 1, 937);
    insert(&myList, 0, 618);
    insert(&myList, 4, 133);
    insert(&myList, 3, 589);
    insert(&myList, 2, 850);

    displayList(&myList);

    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);

    int idx = searchValue(&myList, val);

    if(idx != -1) printf("Element with value %d is at index %d\n", val, idx);
    else printf("Element not found\n");
}