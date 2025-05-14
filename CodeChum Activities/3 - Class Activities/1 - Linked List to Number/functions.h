//CODE HERE
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          // Data part of the node (assuming single digits 0-9)
    struct Node* next; // Pointer to the next node
} Node;


// TODO: Function to create a new node
Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) {
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


// TODO: Function to insert a node at the end of the list
Node *insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if(head == NULL) {
        head = newNode;
        return head;
    }
    
    Node *ptr;
    for(ptr = head; ptr->next != NULL; ptr = ptr->next) {}
    
    ptr->next = newNode;
    return head;
}


// TODO: Function to print the linked list
void printList(Node *head) {
    if(head == NULL) {
        printf("Empty list");
        return;
    }
    
    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d -> ", ptr->data);
    printf("NULL\n");
}


// TODO: Function to free the memory allocated for the list
void freeList(Node *head) {
    Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


// TODO: Function to perform bubble sort on the linked list values

void swapData(Node *a, Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSortValues(Node *head) {
    int swapped;
    Node *ptr, *lastSorted = NULL;
    
    do {
        swapped = 0;
        ptr = head;
        
        while(ptr->next != lastSorted) {
            if(ptr->data > ptr->next->data) {
                swapData(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while(swapped);
}


// TODO: Function to convert sorted linked list values to a number
long listToNumber(Node *head) {
    long num = 0;
    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) {
        num = num * 10 + ptr->data;
    }
    return num;
}