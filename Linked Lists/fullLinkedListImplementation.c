//FULL IMPLEMENTATION OF LINKED LIST OPERATIONS IN ONE FILE
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void insertSorted(node **head, int val) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);

    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL || val < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *trav;
    for(trav = *head; trav->next != NULL && trav->next->data < val; trav = trav->next) {}

    newNode->next = trav->next;
    trav->next = newNode;
}

void insertStart(node **head, int val) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(node **head, int val) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    node *ptr;
    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = newNode;
}

void display(node *head) {
    if(!head) {
        printf("empty\n");
        return;
    }

    for(node *ptr = head; ptr != NULL; ptr = ptr->next) printf("%d -> ", ptr->data);
    printf("NULL\n");
}

void deleteAllOccurrences(node **head, int x) {
    if(!(*head)) {
        printf("empty\n"); 
        return;
    }

    node *temp;
    while(*head && (*head)->data == x) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    node *current = *head;
    while(current && current->next) {
        if(current->next->data == x) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void reverseList(node **head) {
    node *prev = NULL, *next = NULL;
    while(*head != NULL) {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;
}

void deleteEnd(node **head) {
    if(!(*head)) {
        printf("empty\n"); 
        return;
    }

    if((*head)->next == NULL) {
        free(*head);
        head = NULL;
        return;
    }

    node *prev, *ptr;
    for(ptr = *head, prev = NULL; ptr->next != NULL; prev = ptr, ptr = ptr->next) {}

    prev->next = ptr->next;
    free(ptr);
}

void deleteStart(node **head) {
    if(!(*head)) {
        printf("empty\n"); 
        return;
    }

    node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteList(node **head) {
    if(!(*head)) {
        printf("empty\n"); 
        return;
    }

    node *temp;
    while(*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void bubbleSort(node **head) {
    if(!(*head)) {
        printf("empty\n"); 
        return;
    }

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

void selectionSort(node *head) {
    if(!head) return;
    node *current = head;

    while(current != NULL) {
        node *minNode = current, *temp = current->next;

        while(temp != NULL) {
            if(temp->data < minNode->data) minNode = temp;
            temp = temp->next;
        }

        if(minNode != current) {
            int temp = minNode->data;
            minNode->data = current->data;
            current->data = temp;
        }
        current = current->next;
    }
}

int main() {
    node *head = NULL;
    int choice, val;

    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert in sorted order\n");
        printf("4. Display list\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete all occurrences of a value\n");
        printf("8. Delete entire list\n");
        printf("9. Bubble sort list\n");
        printf("10. Selection sort list\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at start: ");
                scanf("%d", &val);
                insertStart(&head, val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 3:
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &val);
                insertSorted(&head, val);
                break;
            case 4:
                display(head);
                break;
            case 5:
                deleteStart(&head);
                break;
            case 6:
                deleteEnd(&head);
                break;
            case 7:
                printf("Enter value to delete all occurrences: ");
                scanf("%d", &val);
                deleteAllOccurrences(&head, val);
                break;
            case 8:
                deleteList(&head);
                break;
            case 9:
                bubbleSort(&head);
                break;
            case 10:
                selectionSort(head);
                break;
            case 11:
                reverseList(&head);
                break;
            case 12:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 12);

    return 0;
}