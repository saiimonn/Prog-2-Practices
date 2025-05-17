#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESC 100
#define MAX_TASKS 50

typedef struct {
    char description[MAX_DESC];
    bool isDone;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskList;

// Function declarations
void addTask(TaskList *list, const char *desc) {
    if(list->count >= MAX_TASKS) {
        printf("Maximum amount of tasks reached\n");
        return;
    }

    for(int i = list->count; i > 0; i--) {
        list->tasks[i] = list->tasks[i - 1];
    }

    list->tasks[0].isDone = false;
    strcpy(list->tasks[0].description, desc);
    list->count++;
}

void removeTask(TaskList *list, const char *desc) {
    if(list->count == 0) {
        printf("No tasks\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->tasks[i].description, desc) == 0) {
            for(int j = i; j < list->count; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            printf("Removed task\n");
            list->count--;
            return;
        }
    }
    printf("Task not found");
}

void markTaskDone(TaskList *list, const char *desc) {
    if(list->count == 0) {
        printf("No tasks\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->tasks[i].description, desc) == 0) {
            list->tasks[i].isDone = true;
            printf("Task done\n");
            return;
        }
    }
    printf("Task not found\n");
}

void listTasks(TaskList list) {
    if(list.count == 0) {
        printf("No tasks\n");
        return;
    }

    for(int i = 0; i < list.count; i++) printf("Task %d:\nDescription: %s\nStatus: %s\n", i + 1, list.tasks[i].description, (list.tasks[i].isDone == true) ? "DONE" : "NOT DONE");
    printf("\n");
}

int main() {
    TaskList todo = {.count = 0};

    addTask(&todo, "Finish assignment");
    addTask(&todo, "Read a book");
    listTasks(todo);

    markTaskDone(&todo, "Read a book");
    listTasks(todo);

    removeTask(&todo, "Finish assignment");
    listTasks(todo);

    return 0;
}