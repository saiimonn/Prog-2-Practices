//READ-ONLY
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Node* head = NULL; // Initialize an empty list

    // Create a sample linked list (max 6 elements assumed)
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 0);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);

    printf("Original List: ");
    printList(head); // Prints the initial data in original node order

    // Sort the linked list values using Bubble Sort
    bubbleSortValues(head);

    printf("List after sorting values: ");
    printList(head); // Prints the sorted data, but nodes are still in original sequence

    // Convert the sorted list data to a number
    long finalNumber = listToNumber(head); // Use long

    printf("\nConverted Number: %ld\n", finalNumber); // Use %ld for long

    // Free the allocated memory
    freeList(head);
    head = NULL;

    return 0;
}