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
    node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d ", ptr->data);
    printf("\n");
}

void nodeConcat(node **list1, node *list2) {
    if(*list1 == NULL) {
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
    printf("Enter size of list 1: ");
    scanf("%d", &size);

    for(int i = 1; i <= size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    printf("Enter size of list 2: ");
    scanf("%d", &size);

    for(int i = 1; i <= size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    nodeConcat(&list1, list2);

    printf("Concatenated list: ");
    printList(list1);
}

/*
Sample Output:

Enter size of list 1: 4
Element 1: 4
Element 2: 3
Element 3: 5
Element 4: 2
Enter size of list 2: 3
Element 1: 6
Element 2: 4
Element 3: 2
List 1: 4 3 5 2 
List 2: 6 4 2 
Concatenated list: 4 3 5 2 6 4 2 
*/