//Delete all occurrences of nodes with a value x
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void insertSorted(node **head, int val) {
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
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

void delete(node **head, int x) {
    node *temp;

    while(*head && (*head)->data == x) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    node *current = *head;
    while(current && current->next) {
        if(current->next->data == x) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else current = current->next;
    }
}

void display(node *head) {
    if(!head) return;

    for(node *ptr = head; ptr != NULL; ptr = ptr->next) printf("%d -> ", ptr->data);
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    insertSorted(&head, 19);
    insertSorted(&head, 48);
    insertSorted(&head, 19);
    insertSorted(&head, 19);
    insertSorted(&head, 47);
    insertSorted(&head, 19);
    insertSorted(&head, 78);

    printf("Initial List:\n");
    display(head);

    delete(&head, 19);

    printf("List after deleting nodes with value 19:\n");
    display(head);
}