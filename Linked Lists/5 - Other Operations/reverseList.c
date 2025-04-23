#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertStart(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head) {
    node *ptr;
    printf("HEAD ->");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf(" %d -> ", ptr->data);
    printf("NULL\n");
}

void reverseList(node **head) {
    node *prev = NULL;
    node *next = NULL;

    while(*head != NULL) {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;
}

int main() {
    node *head = NULL;

    insertStart(&head, 80);
    insertStart(&head, 70);
    insertStart(&head, 60);
    insertStart(&head, 50);
    insertStart(&head, 40);
    insertStart(&head, 30);
    insertStart(&head, 20);
    insertStart(&head, 10);

    printf("Original List: ");
    printList(head);

    reverseList(&head);

    printf("Reversed List: ");
    printList(head);
}

/*
Output: 
Original List: HEAD -> 10 ->  20 ->  30 ->  40 ->  50 ->  60 ->  70 ->  80 -> NULL
Reversed List: HEAD -> 80 ->  70 ->  60 ->  50 ->  40 ->  30 ->  20 ->  10 -> NULL
*/