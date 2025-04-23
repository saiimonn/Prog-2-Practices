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

int getSize(node *head) {
    int count = 0;
    node *trav;
    for(trav = head; trav != NULL; count++, trav = trav->next) {}
    return count;
}

void printMiddle(node *head) {
    int size = getSize(head);
    int middle = size / 2;

    node *ptr = head;
    for(int i = 0; i < middle; i++, ptr = ptr->next) {}

    printf("Middle Node: %d\n", ptr->data);
}

void printList(node *head) {
    node *ptr;
    printf("HEAD ->");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf(" %d -> ", ptr->data);
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    insertStart(&head, 10);
    insertStart(&head, 20);
    insertStart(&head, 30);
    insertStart(&head, 40);
    insertStart(&head, 50);

    printf("List: ");
    printList(head);

    printMiddle(head);
}