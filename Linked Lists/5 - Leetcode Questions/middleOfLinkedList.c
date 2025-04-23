/*
876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
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

    for(ptr = head; ptr != NULL; ptr = ptr->next, count++){}

    return count;
}

struct ListNode* middleNode(struct ListNode* head) {
    int size = getSize(head);
    int middle = size / 2;
    struct ListNode *trav = head;

    for(int i = 0; i < middle; i++) {
        trav = trav->next;
    }

    return trav;
}