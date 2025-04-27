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
}

int getMax(node *head, int size) {
    
    int max = head->data;
    int highestCount = 0;

    for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
        int value = ptr->data;
        int count = 0;
        
        node *trav = head;
        while (trav != NULL) {
            if (trav->data == value) {
                count++;
            }
            trav = trav->next;
        }
        
        if (count > highestCount) {
            highestCount = count;
            max = value;
        }
    }
    
    return max;
}

int main() {
    node *head = NULL;
    int size, val;
    
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    
    for(int i = 1; i <= size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    
    printf("Linked list: ");
    printList(head);
    
    int max = getMax(head, size);\
    
    printf("\nMost repeated element: %d", max);
}

/*
Sample outputs:

Enter size of linked list: 5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 4
Linked list: 1 2 3 4 4
Most repeated element: 4

Enter size of linked list: 5
Enter element 1: 1
Enter element 2: 1
Enter element 3: 2
Enter element 4: 2
Enter element 5: 3
Linked list: 1 1 2 2 3
Most repeated element: 1
*/