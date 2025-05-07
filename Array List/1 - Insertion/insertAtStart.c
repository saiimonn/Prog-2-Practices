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

void insertAtStart(List *list, int val) {
    if(list->size >= MAX) {
        printf("List is full\n");
        return;
    }

    for(int i = list->size; i > 0; i--) list->data[i] = list->data[i - 1];

    list->data[0] = val;
    list->size++;
}