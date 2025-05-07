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

    printf("List Elements: ");
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

int searchIndex(List *list, int idx) {
    if(list->size == 0) {
        printf("List is empty\n");
        return -1;
    }

    for(int i = 0; i < list->size; i++) {
        if(i == idx) return list->data[i];
    }
    return -1;
}

int main() {
    List myList;
    initList(&myList);

    insert(&myList, 0, 40);
    insert(&myList, 0, 20);
    insert(&myList, 1, 80);
    insert(&myList, 0, 140);
    insert(&myList, 3, 429);
    insert(&myList, 1, 510);
    insert(&myList, 2, 849);
    insert(&myList, 3, 746);
    insert(&myList, 7, 151);

    displayList(&myList);

    int idx;
    printf("Enter index to search: ");
    scanf("%d", &idx);

    int val = searchIndex(&myList, idx);

    if(val != -1) printf("Element at index %d is %d\n", idx, val);
    else printf("No element at index %d\n", idx);
}