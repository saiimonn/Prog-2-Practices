#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student {
    char name[50];
    int studentID;
    float gpa;
    struct Student* next;
} Student;

// write your functions here
Student *createStudent(char name[], int studentID, float gpa) {
    // ADD CODE HERE...
    Student *newStudent = malloc(sizeof(Student));
    if(newStudent == NULL) {
        printf("Mem allocation failed.\n");
        exit(0);
    }
    strcpy(newStudent->name, name);
    newStudent->studentID = studentID;
    newStudent->gpa = gpa;
    newStudent->next = NULL;
    return newStudent;
}

Student *insertStudent(Student *head, char name[], int studentID, float gpa) {
    // ADD CODE HERE...
    Student *newStudent = createStudent(name, studentID, gpa);
    newStudent->next = head;
    return newStudent;
}

Student *deleteStudent(Student *head, int studentID) {
    // ADD CODE HERE...
    if(head == NULL) {
        printf("empty list.\n");
        return NULL;
    }

    Student *temp;
    if(head->studentID == studentID) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student with ID %d removed.\n", studentID);
        return head;
    }

    Student *prev;
    for(temp = head, prev = NULL; temp != NULL && temp->studentID != studentID; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        return head;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d removed.\n", studentID);
    return head;
}

void displayStudents(Student *head) {
    // ADD CODE HERE...
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("Student List:\n");
    Student *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("Name: %s, ID: %d, GPA: %.2f\n", ptr->name, ptr->studentID, ptr->gpa);
}

void searchStudentByName(Student *head, char searchName[]) {
    // ADD CODE HERE...
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }

    Student *ptr;
    for(ptr = head; ptr != NULL && strcmp(ptr->name, searchName) != 0; ptr = ptr->next) {}

    if(ptr == NULL) {
        return;
    }

    printf("Student found:\n");
    printf("Name: %s, ID: %d, GPA: %.2f\n", ptr->name, ptr->studentID, ptr->gpa);
}

void freeList(Student *head) {
    // ADD CODE HERE...
    Student *ptr;
    while(head != NULL) {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}