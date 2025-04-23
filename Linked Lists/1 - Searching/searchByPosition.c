//Search the list by entering the position (n) and return the value of the node
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

int searchNode(node *head, int n) {
    int idx = 0;
    for(; head != NULL; idx++, head = head->next) {
        if(idx == n) return head->data;
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

    insertStart(&head, 60);
    insertStart(&head, 200);
    insertStart(&head, 40);
    insertStart(&head, 140);
    insertStart(&head, 620);
    insertStart(&head, 90);
    insertStart(&head, 80);
    insertStart(&head, 130);
    insertStart(&head, 550);

    printList(head);

    int pos;
    printf("Enter position to search: ");
    scanf("%d", &pos);

    int result = searchNode(head, pos);

    if(result != -1) printf("The value of the node at position %d is %d\n", pos, result);
    else printf("Node at position %d is out of bounds\n", pos);
}

/*
Sample output: 

HEAD -> 550 ->  130 ->  80 ->  90 ->  620 ->  140 ->  40 ->  200 ->  60 -> NULL
Enter position to search: 6
The value of the node at position 6 is 40

HEAD -> 550 ->  130 ->  80 ->  90 ->  620 ->  140 ->  40 ->  200 ->  60 -> NULL
Enter position to search: 9
Node at position 9 is out of bounds
*/