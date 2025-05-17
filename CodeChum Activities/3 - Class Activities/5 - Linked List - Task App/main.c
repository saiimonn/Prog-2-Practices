#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    Task* toDoList = NULL;
    int choice;
    char description[100];
    int priority;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline

                printf("Enter task priority: ");
                scanf("%d", &priority);
                getchar(); // Consume newline
                toDoList = insertTask(toDoList, description, priority);
                break;
            case 2:
                printf("Enter task description to delete: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline
                toDoList = deleteTask(toDoList, description);
                break;
            case 3:
                displayTasks(toDoList);
                break;
            case 4:
                freeList(toDoList);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}