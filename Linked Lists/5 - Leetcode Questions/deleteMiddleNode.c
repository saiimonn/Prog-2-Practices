/*
2095. Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getSize(struct ListNode *head) {
    int count = 0;
    struct ListNode *ptr;

    for(ptr = head; ptr != NULL; ptr = ptr->next, count++) {}
    return count;
}

struct ListNode* deleteMiddle(struct ListNode* head) {
    int size = getSize(head);
    int middle = size / 2;
    struct ListNode *prev = NULL;
    struct ListNode *trav = head;

    if (head == NULL || head->next == NULL) {
    free(head);
    return NULL;
}

    for(int i = 0; i < middle; i++, prev = trav, trav = trav->next){}

    prev->next = trav->next;
    free(trav);
    return head;
}