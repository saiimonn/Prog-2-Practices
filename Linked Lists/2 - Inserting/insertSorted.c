//Algo for inserting a node inside a list and keeping it sorted in ascending order
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void insertSorted(node **head, int value) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *trav;
    for(trav = *head; trav->next != NULL && trav->next->data < value; trav = trav->next) {}

    newNode->next = trav->next;
    trav->next = newNode;
} 

void displayList(node *head) {
    if(!head) {
        printf("List is empty\n");
        return;
    }

    for(node *ptr = head; ptr != NULL; ptr = ptr->next) printf("%d -> ", ptr->data);
    printf("NULL\n");
}

void freeList(node *head) {
    node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node *head = NULL;       
    int choice, value;

    do {
        printf("\nMenu\n"
               "1. Insert number (keeps list sorted)\n"
               "2. Display list\n"
               "0. Exit\n"
               "Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                if (scanf("%d", &value) == 1)
                    insertSorted(&head, value);
                else
                    printf("Invalid input.\n");
                break;
            case 2:
                displayList(head);
                break;
            case 0:
                freeList(head);
                printf("Good-bye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}