#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void insertStart(node **head, int val) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void displayList(node *head) {
    if(!head) return;

    for(node *ptr = head; ptr != NULL; ptr = ptr->next) printf("%d -> ", ptr->data);
    printf("NULL\n");
}

void swap(node *a, node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void selectionSort(node *head) {
    if(!head) return;

    node *current = head;
    while(current != NULL) {
        node *minNode = current;
        node *temp = current->next;

        while(temp != NULL) {
            if(temp->data < minNode->data) minNode = temp;
            temp = temp->next;
        }

        if(minNode != current) {
            swap(&current->data, &minNode->data);
        }

        current = current->next;
    }
}

int main() {
    node *head = NULL;

    insertStart(&head, 58);
    insertStart(&head, 28);
    insertStart(&head, 19);
    insertStart(&head, 47);
    insertStart(&head, 30);
    insertStart(&head, 36);
    insertStart(&head, 29);

    printf("Initial List:\n");
    displayList(head);

    selectionSort(head);

    printf("List after selection sort:\n");
    displayList(head);
}