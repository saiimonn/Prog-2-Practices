#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char str[50];
    struct node *next;
} node;

void insertSorted(node **head, int id, const char *str) {
    node *newNode = malloc(sizeof(node));
    if(!newNode) exit(0);
    newNode->id = id;
    strcpy(newNode->str, str);
    newNode->next = NULL;
    
    if(*head == NULL || id < (*head)->id) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *trav;
    for(trav = *head; trav->next != NULL && trav->next->id < id; trav = trav->next) {}

    newNode->next = trav->next;
    trav->next = newNode;
}

void sortString(node **head) {
    int swapped;
    node *ptr, *lastSorted = NULL;

    do {
        swapped = 0;
        ptr = *head;
        while(ptr->next != lastSorted) {
            if(strcmp(ptr->str, ptr->next->str) > 0) {
                int temp = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = temp;

                char tempStr[50];
                strcpy(tempStr, ptr->str);
                strcpy(ptr->str, ptr->next->str);
                strcpy(ptr->next->str, tempStr);

                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while (swapped);
}

void display(node *head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    node *ptr;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        printf("[%d, %s] -> ", ptr->id, ptr->str);
    printf("NULL\n");
}

int main(){
    node *head = NULL;

    insertSorted(&head, 3, "banana");
    insertSorted(&head, 1, "apple");
    insertSorted(&head, 2, "cherry");

    printf("Before string sort:\n");
    display(head);

    sortString(&head);

    printf("After string sort:\n");
    display(head);
}  