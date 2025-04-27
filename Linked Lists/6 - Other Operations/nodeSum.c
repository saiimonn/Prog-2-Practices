//Creating a list (sumList) whose data is the sum of two lists (list1 and list2)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
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

node *createNode(int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
}

node *getSums(node *list1, node *list2) {
    node *sumList = NULL;
    node **ptr = &sumList;

    while(list1 != NULL && list2 != NULL) {
        int sum = list1->data + list2->data;

        node *newNode = createNode(sum);

        *ptr = newNode;
        ptr =  &(newNode)->next;

        list1 = list1->next;
        list2 = list2->next;
    }

    while(list1 != NULL) {
        node *newNode = createNode(list1->data);

        *ptr = newNode;
        ptr = &(newNode)->next;

        list1 = list1->next;
    }

    while(list2 != NULL) {
        node *newNode = createNode(list2->data);

        *ptr = newNode;
        ptr = &(newNode)->next;

        list2 = list2->next;
    }

    return sumList;
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
    
    node *sumList = getSums(list1, list2);
    
    printf("Sum: ");
    printList(sumList);
}