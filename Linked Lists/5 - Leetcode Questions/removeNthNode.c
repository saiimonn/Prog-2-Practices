/*
19. Remove Nth Node From End Of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reverseList(struct ListNode **head) {
    struct ListNode *prev = NULL, *next = NULL;

    while(*head != NULL) {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    reverseList(&head);
    
    if (n == 1) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    } else {
        struct ListNode *prev = NULL, *ptr = head;
        int idx = 1;
        while (idx != n) {
            prev = ptr;
            ptr = ptr->next;
            idx++;
        }
        prev->next = ptr->next;
        free(ptr);
    }

    reverseList(&head);
    return head;
}