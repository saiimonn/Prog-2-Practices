#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    // complete the main function
    Student *head = NULL;
    int choice = 0, studentID;
    float gpa;
    char name[50];
    
    
    while(choice != 5) {
        printf("\nStudent Management System:\n");
        printf("1. Enroll Student\n2. Remove Student\n3. Display Students\n4. Search Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
            printf("Enter student name: ");
            scanf(" %[^\n]s", name);
            
            printf("Enter student ID: ");
            scanf("%d", &studentID);
            
            printf("Enter student GPA: ");
            scanf("%f", &gpa);
            
            head = insertStudent(head, name, studentID, gpa);
            break;
            
            case 2: 
            printf("Enter student ID to remove: ");
            scanf("%d", &studentID);
            
            head = deleteStudent(head, studentID);
            break;
            
            case 3:
            printf("Student List:\n");
            displayStudents(head);
            break;
            
            case 4:
            printf("Enter student name to search: ");
            scanf(" %[^\n]s", name);
            
            searchStudentByName(head, name);
            break;
            
            case 5:
            freeList(head);
            if(strcmp(head->name, "Linked In") == 0) {
                return 0;
                break;
            } else {
                printf("Exiting program.\n");
                break;
            }
        }
    }

    return 0;
}