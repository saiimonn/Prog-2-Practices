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

void printList(node *head) {
    node *ptr;
    printf("HEAD ->");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf(" %d -> ", ptr->data);
    printf("NULL\n");
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

    printList(head);

    int val;
    printf("Enter the value you wish to find: ");
    scanf("%d", &val);

    int result = searchNode(head, val);

    if(result != -1) printf("%d is found at index %d\n", val, result);
    else printf("%d is not found in the list.\n", val);
}

/*
Sample outputs:

HEAD -> 10 ->  10 ->  30 ->  20 ->  80 ->  40 ->  90 -> NULL
Enter the value you wish to find: 30
30 is found at index 2

HEAD -> 10 ->  10 ->  30 ->  20 ->  80 ->  40 ->  90 -> NULL
Enter the value you wish to find: 70
70 is not found in the list.
*/