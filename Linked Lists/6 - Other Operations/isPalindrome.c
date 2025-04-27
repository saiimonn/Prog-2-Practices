#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void insertStart(node **head ,int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(node *head) {
    node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d ", ptr->data);
    printf("\n");
}

node *reverseList(node *head) {
    node *prev = NULL, *next = NULL;
    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int isPalindrome(node *head) {
    if(head == NULL || head->next == NULL) return 1;
    node *slow = head;
    node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *firstHalf = head;
    node *secondHalf = reverseList(slow);
    int isPalindrome = 1;
    while(secondHalf != NULL) {
        if(firstHalf->data != secondHalf->data) {
            isPalindrome = 0;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return isPalindrome;
}

int main() {
    node *head = NULL;

    int n;

    insertStart(&head, 6);
    insertStart(&head, 4);
    insertStart(&head, 0);
    insertStart(&head, 4);
    insertStart(&head, 7);


    printf("List: ");
    printList(head);

    int palindrome = isPalindrome(head);

    if(palindrome == 1) {
        printf("List is a palindrome\n");
    } else {
        printf("List isn't a palindrome\n");
    }
}

/*
List: 5 0 0 0 5 
List is a palindrome

List: 7 4 0 4 6 
List isn't a palindrome
*/