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

// Implement these:
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

int deleteByID(Node **head, int id) {
    if(*head == NULL) {
        printf("List is empty\n");
        return 0;
    }

    Node *ptr, *prev;
    for(ptr = *head, prev = NULL; ptr != NULL && ptr->data.id != id; prev = ptr, ptr = ptr->next) {}

    if(ptr == NULL) {
        return 0;
    }

    if(prev == NULL) {
        *head = ptr->next;
    } else {
        prev->next = ptr->next;
    }

    free(ptr);
    return 1;
}

Student* searchByName(Node *head, const char *name) {

    Node *trav;
    for(trav = head; trav != NULL; trav = trav->next) {
        if(strcmp(trav->data.name, name) == 0) {
            Student *temp = malloc(sizeof(Student));
            temp->gpa = trav->data.gpa;
            strcpy(temp->name, trav->data.name);
            temp->id = trav->data.id;
            return temp;
        }
    }
    return NULL;
}

void displayList(Node *head) {
    if(head == NULL) {
        printf("Empty list\n");
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

    insertAtEnd(&head, s1);
    insertAtEnd(&head, s2);
    insertAtEnd(&head, s3);

    printf("All Students:\n");
    displayList(head);

    printf("\nDeleting student with ID 102...\n");
    if (deleteByID(&head, 102))
        printf("Deleted successfully.\n");
    else
        printf("Student not found.\n");

    printf("\nSearching for Charlie:\n");
    Student *found = searchByName(head, "Charlie");
    if (found)
        printf("Found: ID=%d, Name=%s, GPA=%.2f\n", found->id, found->name, found->gpa);
    else
        printf("Charlie not found.\n");

    printf("\nFinal List:\n");
    displayList(head);

    return 0;
}