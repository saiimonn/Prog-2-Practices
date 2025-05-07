/*
Concatenate Lists
by CodeChum Admin
Write a program to concatenate two singly linked lists.
Sample Output 1

Enter size of first linked list: 3
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter size of second linked list: 3
Enter element 1: 4
Enter element 2: 5
Enter element 3: 6
First linked list: 1 2 3
Second linked list: 4 5 6
Concatenated linked list: 1 2 3 4 5 6
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertEnd(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    node *ptr;
    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = newNode;
}

void printList(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d ", ptr->data);
    printf("\n");
}

void concatenateList(node **list1, node *list2) {
    if(*list1 == NULL && list2 == NULL) {
        printf("Both lists are empty!\n");
        return;
    } else if(*list1 == NULL) {
        *list1 = list2;
        return;
    }

    node *ptr;
    for(ptr = *list1; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = list2;
}

int main() {
    node *list1 = NULL, *list2 = NULL;
    int size, val;

    printf("Enter size of first linked list: ");
    scanf("%d", &size);

    for(int i = 1; i <= size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    printf("Enter size of second linked list: ");
    scanf("%d", &size);

    for(int i = 1; i <= size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    printf("First linked list: ");
    printList(list1);

    printf("Second linked list: ");
    printList(list2);

    concatenateList(&list1, list2);

    printf("Concatenated linked list: ");
    printList(list1);
}