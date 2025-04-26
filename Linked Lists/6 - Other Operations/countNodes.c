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

int getSize(node *head) {
    int count = 0;
    node *ptr;
    for(ptr = head; ptr != NULL; count++, ptr = ptr->next) {}
    return count;
}

int main() {
    node *head = NULL;

    insertStart(&head, 23);
    insertStart(&head, 56);
    insertStart(&head, 12);
    insertStart(&head, 34);
    insertStart(&head, 54);
    insertStart(&head, 45);
    insertStart(&head, 23);
    insertStart(&head, 67);
    insertStart(&head, 47);
    insertStart(&head, 94);

    printf("List:\n");
    printList(head);

    int count = getSize(head);

    printf("There are %d nodes in the list\n", count);
}