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

void removeList(node **head) {
    node *temp;
    while(*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
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

    removeList(&head);
    
    printf("List after removing: ");
    printList(head);
}

/*
Output:

List: HEAD -> 90 ->  80 ->  20 ->  30 ->  50 -> NULL
List after removing: List is empty!
*/