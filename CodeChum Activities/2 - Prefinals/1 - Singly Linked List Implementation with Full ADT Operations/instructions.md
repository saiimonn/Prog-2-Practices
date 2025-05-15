## Singly Linked List Implementation with Full ADT Operations
## by Christine Bandalan

Write a C program that implements a singly linked list supporting the following Abstract Data Type (ADT) operations.

## Required Operations:

- Display all elements of the linked list in order.
- Insert a new node at the front of the list.
- Update the data value of a node at a given index.
- Delete the first node (front).
- Free all dynamically allocated memory before the program exits.

## Data Structure:
Define a struct Node with:
- An integer data to store the value.
- A pointer next to the next node.

# Additional Requirements:
Each operation must be implemented in its own function.
Properly handle edge cases (e.g., inserting into an empty list, deleting from an empty list, invalid indexes).
Display appropriate messages if operations cannot be performed (e.g., "Index out of range", "List is empty", "Value not found").
Use dynamic memory allocation (malloc, free) for node creation and destruction.

# User Interaction:
Present a menu that allows the user to select an operation repeatedly until they choose to exit.
The program should not crash even with invalid input or operations.