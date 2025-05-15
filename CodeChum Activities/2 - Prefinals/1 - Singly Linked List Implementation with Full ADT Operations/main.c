#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void traverse(Node* head);
void insertFront(Node** head, int data);
void insertLast(Node** head, int data);
void insertAtIndex(Node** head, int index, int data);
void updateAtIndex(Node* head, int index, int newData);
void deleteFront(Node** head);
void freeList(Node* head);

int main() {
    Node* head = NULL;
    int choice, data, index;

    do {
        printf("\nSingly Linked List Operations\n");
        printf("1. Traverse\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at Last\n");
        printf("4. Insert at Index\n");
        printf("5. Update at Index\n");
        printf("6. Delete Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(head);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 3:
                printf("Enter value to insert at last: ");
                scanf("%d", &data);
                insertLast(&head, data);
                break;
            case 4:
                printf("Enter index and value to insert: ");
                scanf("%d %d", &index, &data);
                insertAtIndex(&head, index, data);
                break;
            case 5:
                printf("Enter index and new value to update: ");
                scanf("%d %d", &index, &data);
                updateAtIndex(head, index, data);
                break;
            case 6:
                deleteFront(&head);
                break;
            case 7:
                printf("Exiting...\n");
                freeList(head);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Traverse the list
void traverse(Node* head) {
    //ADD CODE HERE...
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *ptr;
    printf("Linked List: ");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d -> ", ptr->data);
    printf("NULL\n");
}

// Insert at the front
void insertFront(Node** head, int data) {
    //ADD CODE HERE...
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the last
void insertLast(Node** head, int data) {
    //ADD CODE HERE...
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *ptr;
    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}
    
    ptr->next = newNode;
}

// Insert at a specific index
void insertAtIndex(Node** head, int index, int data) {
    //ADD CODE HERE...
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node *ptr = *head;
    for(int i = 1; i < index - 1 && ptr != NULL; i++, ptr = ptr->next) {}

    if(ptr == NULL) {
        printf("Index out of range.\n");
        return;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Update node at specific index
void updateAtIndex(Node* head, int index, int newData) {
    //ADD CODE HERE...
    
    if(index == 0) {
        head->data = newData;
        return;
    }
    
    Node *ptr;
    int i = 0;
    for(ptr = head; ptr != NULL && i < index; ptr = ptr->next, i++) {}
    
    if(ptr == NULL) {
        printf("Index out of range.\n");
        return;
    }
    
    ptr->data = newData;
}

// Delete the first node
void deleteFront(Node** head) {
    //ADD CODE HERE...
    if(*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
    
    printf("First node deleted.\n");
}

// Free the entire list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}