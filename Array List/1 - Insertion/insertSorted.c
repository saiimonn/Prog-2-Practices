//Algo for inserting elements in the list while keeping it sorted(Ascending order)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int count;
} List;

void insertSorted(List *list, int val) {
    if(list->count >= MAX) {
        printf("List has reached maximum capacity\n");
        return;
    }

    int idx = 0;
    while(idx < list->count && list->data[idx] <= val) idx++;

    for(int i = list->count; i > idx; list->data[i] = list->data[i - 1], i--) {}

    list->data[idx] = val;
    list->count++;
}

void displayList(List list) {
    if (list.count == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("List (sorted): ");
    for (int i = 0; i < list.count; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

int main() {
    List list;
    list.count = 0;

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Display list\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertSorted(&list, value);
                break;
            case 2:
                displayList(list);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 0);

    return 0;
}