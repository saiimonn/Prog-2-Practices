/*
237. Delete Node in a Linked List

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
//Assigns the node to be deleted (node) as the node after it. 
//so if it were deleteNode(3), 1->2->3->4->5 it would then be 1->2->4->5 once the function is finished

void deleteNode(struct ListNode* node) {
    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
}
/*
If you actually want to delete a node and free up some memory.
1->2->3->4->5 (original list)

1->2->4->4->5 (you assign temp as the next node and assign the node passed in the function with the val and next of the node after it)

1->2->4->5 (after freeing temp)
*/