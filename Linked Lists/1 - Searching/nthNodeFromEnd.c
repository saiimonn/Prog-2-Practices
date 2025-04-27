#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertStart(node **head ,int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head) {
    node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d ", ptr->data);
    printf("\n");
}

int getNode(node *head, int n) {
    node *first = head, *second = head;

    for(int i = 0; i < n; i++) {
        if(first == NULL) {
            return;
        }

        first = first->next;
    }

    while(first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second->data;
}

int main() {
    node *head = NULL;

    int n;

    insertStart(&head, 10);
    insertStart(&head, 50);
    insertStart(&head, 160);
    insertStart(&head, 245);
    insertStart(&head, 262);
    insertStart(&head, 373);
    insertStart(&head, 366);
    insertStart(&head, 278);
    insertStart(&head, 841);
    insertStart(&head, 357);
    insertStart(&head, 122);
    insertStart(&head, 245);

    printf("List: ");
    printList(head);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("The %dth node from the end of the list is %d\n", n, getNode(head, n));
}

/*
List: 245 122 357 841 278 366 373 262 245 160 50 10 
Enter n: 5
The 5th node from the end of the list is 262
*/