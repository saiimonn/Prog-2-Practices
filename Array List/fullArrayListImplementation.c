#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int count;
} List;

void initializeList(List *list) {
    list->count = 0;
}

void insertSorted(List *list, int val) {
    if(list->count >= MAX) {
        printf("max capacity reached\n");
        return;
    }

    int idx;
    for(idx = 0; idx < list->count && list->data[idx] <= val; idx++) {}

    for(int i = list->count; i > idx; list->data[i] = list->data[i - 1], i--) {}

    list->data[idx] = val;
    list->count++;
}

void insertFirst(List *list, int val) {
    if(list->count >= MAX) {
        printf("max capacity reached\n");
        return;
    }

    for(int i = list->count; i > 0; list->data[i] = list->data[i - 1], i--) {}

    list->data[0] = val;
    list->count++;
}

void insertLast(List *list, int val) {
    if(list->count >= MAX) {
        printf("max capacity reached\n");
        return;
    }

    list->data[list->count++] = val;
}

void deleteFirst(List *list) {
    if(list->count == 0) {
        printf("Empty\n");
        return;
    }

    for(int i = 0; i < list->count - 1; i++) list->data[i] = list->data[i + 1];
    
    list->count--;
}

void deleteLast(List *list) {
    if(list->count == 0) {
        printf("Empty\n");
        return;
    }

    list->count--;
}

void deleteAtIndex(List *list, int idx) {
    if(list->count == 0) {
        printf("Empty");
        return;
    }

    if(idx < 0 || idx >= list->count) {
        printf("Out of bounds\n");
        return;
    }

    for(int i = idx; i < list->count - 1; i++) list->data[i] = list->data[i + 1];

    list->count--;
}

int main() {
    List myList;
    initializeList(&myList);

    int choice, value;
}