#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int id;
    struct node *next;
} node;

void insertSorted(node **head, int val, int id) {
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->id = id;
    newNode->next = NULL;

    if(*head == NULL || val < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *trav;
    for(trav = *head; trav->next != NULL && trav->next->data < val; trav = trav->next) {}

    newNode->next = trav->next;
    trav->next = newNode;
}

void delete(node **head, int id) {
    if(!(*head)) return;

    node *ptr;
    if((*head)->id == id) {
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
        return;
    }

    node *prev;
    for(ptr = *head, prev = NULL; ptr != NULL && ptr->id != id; prev = ptr, ptr = ptr->next) {}

    if(!ptr) return;

    prev->next = ptr->next;
    free(ptr);
}

void displayList (node *head) {
    if(!head) {
        printf("empty\n");
        return;
    }

    for(node *ptr = head; ptr != NULL; ptr = ptr->next) printf("{ID: %d, Data: %d} -> ", ptr->id, ptr->data);
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    insertSorted(&head, 40, 1);
    insertSorted(&head, 80, 2);
    insertSorted(&head, 23, 3);
    insertSorted(&head, 99, 4);
    insertSorted(&head, 17, 5);
    insertSorted(&head, 48, 6);
    insertSorted(&head, 58, 7);

    printf("Initial list:\n");
    displayList(head);

    delete(&head, 4);

    printf("After deleting node with ID 4:\n");
    displayList(head);
}