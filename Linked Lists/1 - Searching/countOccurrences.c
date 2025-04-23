//Counting the occurrences of a value n
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

int countOccurrence(node *head, int n) {
    int count = 0;
    for(; head != NULL; head = head->next) {
        if(head->data == n) count++;
    }

    return count;
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
    insertStart(&head, 60);
    insertStart(&head, 140);
    insertStart(&head, 620);
    insertStart(&head, 60);
    insertStart(&head, 80);
    insertStart(&head, 130);
    insertStart(&head, 550);

    printList(head);

    int val;
    printf("Enter value to count: ");
    scanf("%d", &val);

    int count = countOccurrence(head, val);

    if(count > 0) printf("There are %d occurrences of the value %d in the list\n", count, val);
    else printf("There are no occurrences of the value %d in the list\n", val);
}

/*
Sample Outputs: 

HEAD -> 550 ->  130 ->  80 ->  60 ->  620 ->  140 ->  60 ->  200 ->  60 -> NULL
Enter value to count: 60
There are 3 occurrences of the value 60 in the list


HEAD -> 550 ->  130 ->  80 ->  60 ->  620 ->  140 ->  60 ->  200 ->  60 -> NULL
Enter value to count: 100
There are no occurrences of the value 100 in the list
*/