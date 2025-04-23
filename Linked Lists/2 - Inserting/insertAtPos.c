#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertAtPos(node **head, int data, int pos) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(pos == 1 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *ptr = *head;
    for(int i = 1; i < pos - 1 && ptr != NULL; i++, ptr = ptr->next) {}

    if(ptr == NULL) {
        printf("Out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

void printList(node *head) {
    node *ptr;
    printf("HEAD ->");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf(" %d -> ", ptr->data);
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    insertAtPos(&head, 20, 3);
    insertAtPos(&head, 25, 1);
    insertAtPos(&head, 30, 2);

    printf("List: ");
    printList(head);
}