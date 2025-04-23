//Searching the node with the value k (first occurrence)
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

int searchNode(node *head, int k) {
    int idx = 0;
    for(; head != NULL; idx++, head = head->next) {
        if(head->data == k) return idx;
    }
    return -1;
}

int main() {
    node *head = NULL;

    insertStart(&head, 90);
    insertStart(&head, 40);
    insertStart(&head, 80);
    insertStart(&head, 20);
    insertStart(&head, 30);
    insertStart(&head, 10);
    insertStart(&head, 10);

    int val;
    printf("Enter the value you wish to find: ");
    scanf("%d", &val);

    int result = searchNode(head, val);

    if(result != -1) printf("%d is found at index %d\n", val, result);
    else printf("%d is not found in the list.\n", val);
}