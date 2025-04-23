#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertStart(node **head, int data ) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *ptr;
    printf("HEAD ->");
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf(" %d -> ", ptr->data);
    printf("NULL\n");
}

void removeAtPos(node **head, int idx) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    } else if (idx == 0) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node *prev, *ptr;
    int i;
    for(i = 0, prev = NULL, ptr = *head; i < idx && ptr != NULL; i++, prev = ptr, ptr = ptr->next) {}

    if(ptr == NULL) {
        printf("Index is out of bounds\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
}

int main() {
    node *head = NULL;

    insertStart(&head, 50);
    insertStart(&head, 30);
    insertStart(&head, 20);
    insertStart(&head, 80);
    insertStart(&head, 90);

    printf("List: ");
    printList(head);

    int idx;
    printf("Enter index to delete: ");
    scanf("%d", &idx);

    removeAtPos(&head, idx);

    printf("List after deleting node at index %d: ", idx);
    printList(head);
}

/*
Sample outputs: 

List: HEAD -> 90 ->  80 ->  20 ->  30 ->  50 -> NULL
Enter index to delete: 3
List after deleting node at index 3: HEAD -> 90 ->  80 ->  20 ->  50 -> NULL

List: HEAD -> 90 ->  80 ->  20 ->  30 ->  50 -> NULL
Enter index to delete: 0
List after deleting node at index 0: HEAD -> 80 ->  20 ->  30 ->  50 -> NULL
*/