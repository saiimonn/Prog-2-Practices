#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char description[100];
    int priority;
    struct Task* next;
} Task;

// TODO: Function to create a new task
Task *createTask(const char *description, int priority) {
    // Implement this function
    Task *newTask = malloc(sizeof(Task));
    if(newTask == NULL) {
        exit(0);
    }
    strcpy(newTask->description, description);
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

// TODO: Function to insert a task based on priority (descending)
Task *insertTask(Task *head, const char *description, int priority) {
    // Implement this function
    Task *newTask = createTask(description, priority);

    if(head == NULL || head->priority < priority) {
        head = newTask;
        return;
    }

    Task *trav;
    for(trav = head; trav->next != NULL && trav->next->priority >= priority; trav = trav->next) {}

    newTask->next = trav->next;
    trav->next = newTask;
    return head;
}

// TODO: Function to delete a task by description
Task *deleteTask(Task *head, const char *description) {
    // Implement this function
    if(head == NULL) {
        return NULL;
    }

    Task *temp;
    if(strcmp(temp->description, description) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Task *prev;
    for(temp = head, prev = NULL; temp != NULL && strcmp(temp->description, description) != 0; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Task with description not found.\n");
        return NULL;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// TODO: Function to display all tasks in the list
void displayTasks(Task *head) {
    // Implement this function
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("To-Do List:\n");
    Task *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("Priority: %d, Description: %s\n", ptr->priority, ptr->description);
}

// TODO: Function to free the memory used by the list
void freeList(Task *head) {
    // Implement this function
    Task *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}