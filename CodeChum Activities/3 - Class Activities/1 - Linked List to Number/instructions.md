## Linked List to Number
## by Edwin Bartlett

## Core Functions

**a. List Creation (insertAtEnd)** 
Nodes are added to the end of the list.
The insertAtEnd function takes the current head of the list and the data for the new node.
It first creates a new node using createNode.
If the list is empty (head == NULL), the new node becomes the head.
Otherwise, it traverses the list until it finds the last node (where current->next == NULL) and appends the new node there.

**b. Value Sorting (bubbleSortValues, swapData)**
bubbleSortValues: Implements the Bubble Sort algorithm to sort the data values within the nodes.
swapData: A simple helper function that takes pointers to two nodes and swaps their data members using a temporary variable.

**c. Conversion to Number (listToNumber)**
This function iterates through the linked list (which now contains sorted data values).
It builds a long integer (num) representing the number formed by the digits.
In each iteration:
It multiplies the current num by 10 (shifting existing digits to the left).
It adds the data from the current node to num.
Example: If num is 10 and current->data is 4, num becomes 10 * 10 + 4 = 104.
It includes a counter (count) and a warning if the list appears to have more than the assumed maximum of 6 elements, as this could lead to overflow when using a long.
Returns the final long integer.

## Utility Functions

**createNode(int data):** Allocates memory for a new Node, initializes its data field, sets next to NULL, and returns a pointer to the new node. Includes basic error checking for malloc.

**printList(Node* head):** Traverses the list from the head and prints the data value of each node, followed by " -> ". Prints "NULL" at the end.

**freeList(Node* head):** Deallocates the memory used by each node in the list to prevent memory leaks. It iterates through the list, storing the next pointer, freeing the current node, and then moving to the stored next node.