#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertStart(node **head, int data ) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *ptr;
    printf("HEAD ->");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf(" %d -> ", ptr->data);
    printf("NULL\n");
}

void removeLast(node **head) {
    if(*head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    if((*head)->next == NULL) {
        free(*head);
        return;
    }

    node *prev, *ptr;

    for(prev = NULL, ptr = *head; ptr->next != NULL; prev = ptr, ptr = ptr->next) {}

    prev->next = NULL;
    free(ptr);
}

int main() {
    node *head = NULL;

    insertStart(&head, 50);
    insertStart(&head, 30);
    insertStart(&head, 20);
    insertStart(&head, 80);
    insertStart(&head, 90);

    printf("List: ");
    printList(head);

    removeLast(&head);

    printf("List after removing last node: ");
    printList(head);
}

/*
Output: 

List: HEAD -> 90 ->  80 ->  20 ->  30 ->  50 -> NULL
List after removing last node: HEAD -> 90 ->  80 ->  20 ->  30 -> NULL
*/