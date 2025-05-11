#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

typedef struct node {
    Student data;
    struct node *next;
} Node;

void insertAtEnd(Node **head, Student data) {
    Node *newStudent = malloc(sizeof(Node));

    newStudent->data = data;
    newStudent->next = NULL;

    if(*head == NULL) {
        *head = newStudent;
        return;
    }

    Node *ptr;

    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = newStudent;
}

//implement these:
void insertAtPosition(Node **head, Student data, int position) {
    Node *newStudent = malloc(sizeof(Student));
    newStudent->data = data;
    newStudent->next = NULL;

    if(*head == NULL) {
        *head = newStudent;
        return;
    }

    Node *ptr = *head;
    for(int i = 1; i < position - 1; i++, ptr = ptr->next) {}

    if(ptr == NULL) {
        printf("Out of bounds\n");
        return;
    }

    newStudent->next = ptr->next;
    ptr->next = newStudent;
}

void updateStudentGPA(Node *head, int id, float newGPA) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) {
        if(ptr->data.id == id) {
            ptr->data.gpa = newGPA;
            return;
        }
    }
    return;
}

int getListLength(Node *head) {
    if(head == NULL) {
        return 0;
    }

    Node *ptr;
    int count = 0;
    for(ptr = head; ptr != NULL; ptr = ptr->next) count++;

    return count;
}

void clearList(Node **head) {
    Node *ptr;
    while(*head != NULL) {
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

void displayList(Node *head) {
    if(head == NULL) {
        printf("Empty\n");
        return;
    }

    Node *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("{%d, %s, %.2f} -> ", ptr->data.id, ptr->data.name, ptr->data.gpa);
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    Student s1 = {101, "Alice", 3.7};
    Student s2 = {102, "Bob", 3.5};
    Student s3 = {103, "Charlie", 3.9};
    Student s4 = {104, "Dana", 3.6};

    insertAtEnd(&head, s1);
    insertAtEnd(&head, s2);
    insertAtEnd(&head, s3);

    printf("Initial List:\n");
    displayList(head);

    printf("\nInserting Dana at position 2:\n");
    insertAtPosition(&head, s4, 2);
    displayList(head);

    printf("\nUpdating GPA of student with ID 103 to 4.0...\n");
    updateStudentGPA(head, 103, 4.0);
    displayList(head);

    printf("\nCurrent list length: %d\n", getListLength(head));

    printf("\nClearing list...\n");
    clearList(&head);
    displayList(head);  // Should print nothing or "List is empty"

    return 0;
}