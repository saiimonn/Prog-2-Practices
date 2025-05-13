#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char trackingID[20];
    char destination[100];
    float weight;
    int priority;
} Package;

typedef struct Node{
    Package data;
    struct Node *next;
} Node;

void addPackage(Node **head, Package data) {
    Node *newPackage = malloc(sizeof(Node));
    newPackage->data = data;
    newPackage->next = *head;
    *head = newPackage;
}
// ➤ Add a package to the front of the list (urgent delivery).

void removePackageByTrackingID(Node **head, const char *trackingID) {
    if(*head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node *temp;
    if(strcmp((*head)->data.trackingID, trackingID) == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *prev;
    for(temp = *head, prev = NULL; temp != NULL && strcmp(temp->data.trackingID, trackingID) != 0; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Tracking ID not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
// ➤ Remove package by tracking ID.

Node* getHeaviestPackage(Node *head) {
    if(head == NULL) {
        printf("Empty\n");
        return NULL;
    }

    Node *max = head;

    if(head->next == NULL) {
        return max;
    }

    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) {
        if(ptr->data.weight > max->data.weight) {
            max = ptr;
        }
    }
    return max;
}
// ➤ Return node containing the heaviest package.

void sortPackagesByPriority(Node **head) {
    int swapped;
    Node *ptr, *lastSorted = NULL;

    do {
        swapped = 0;
        ptr = *head;

        while(ptr->next != lastSorted) {
            if(ptr->data.priority > ptr->next->data.priority) {
                int temp = ptr->data.priority;
                ptr->data.priority = ptr->next->data.priority;
                ptr->next->data.priority = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while(swapped);
}
// ➤ Sort the list in ascending order of priority (1 before 2 before 3).

void displayPackages(Node *head) {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("{%s, %s, %.2f, %d} -> ", ptr->data.trackingID, ptr->data.destination, ptr->data.weight, ptr->data.priority);
    printf("NULL\n");
}
// ➤ Print all packages neatly.

void filterByDestination(Node *head, const char *destination) {
    if(head == NULL) {
        printf("Empty\n");
        return;
    }

    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) {
        if(strcmp(ptr->data.destination, destination) == 0) {
            printf("{%s, %s, %.2f, %d} -> ", ptr->data.trackingID, ptr->data.destination, ptr->data.weight, ptr->data.priority);
        }
    }
    printf("NULL\n");
}
// ➤ Show only packages going to a given destination.

void deleteLowPriority(Node **head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp;
    while(*head != NULL && (*head)->data.priority == 3) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node *ptr = *head, *prev = NULL;
    while(ptr != NULL) {
        if(ptr->data.priority == 3) {
            temp = ptr;
            prev->next = ptr->next;
            ptr = ptr->next;
            free(temp);
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
}
// ➤ Delete all packages with priority 3.

int main() {
    Node *head = NULL;

    Package p1 = {"TRK123", "New York", 2.5, 2};
    Package p2 = {"TRK456", "Los Angeles", 3.8, 1};
    Package p3 = {"TRK789", "Chicago", 1.2, 3};
    Package p4 = {"TRK321", "New York", 5.0, 1};

    addPackage(&head, p1);
    addPackage(&head, p2);
    addPackage(&head, p3);
    addPackage(&head, p4);

    printf("All Packages:\n");
    displayPackages(head);

    printf("\nHeaviest Package:\n");
    Node *heavy = getHeaviestPackage(head);
    if (heavy)
        printf("Tracking ID: %s, Weight: %.2fkg\n", heavy->data.trackingID, heavy->data.weight);

    printf("\nSorted by Priority:\n");
    sortPackagesByPriority(&head);
    displayPackages(head);

    printf("\nFiltering packages going to New York:\n");
    filterByDestination(head, "New York");

    printf("\nDeleting all low-priority packages...\n");
    deleteLowPriority(&head);
    displayPackages(head);

    printf("\nRemoving package TRK456...\n");
    removePackageByTrackingID(&head, "TRK456");
    displayPackages(head);

    return 0;
}