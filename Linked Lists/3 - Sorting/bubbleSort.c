//Implementing bubble sort in linked list. Not recommended XD
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

void bubbleSortLinkedList(node **head) {
    int swapped;
    node *ptr, *lastSorted = NULL;

    do {
        swapped = 0;
        ptr = *head;

        while(ptr->next != lastSorted) {
            if(ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while(swapped);
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

    printf("Original Linked List: ");
    printList(head);

    bubbleSortLinkedList(&head);

    printf("Sorted Linked List with bubble sort: ");
    printList(head);
}

/* 
Output: 

Original Linked List: HEAD -> 550 ->  130 ->  80 ->  90 ->  620 ->  140 ->  40 ->  200 ->  60 -> NULL
Sorted Linked List with bubble sort: HEAD -> 40 ->  60 ->  80 ->  90 ->  130 ->  140 ->  200 ->  550 ->  620 -> NULL
*/