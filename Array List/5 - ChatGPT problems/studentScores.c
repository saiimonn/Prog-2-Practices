#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50

typedef struct {
    char name[30];
    float score;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} StudentList;

void initStudentList(StudentList *list) {
    list->count = 0;
}
// Initializes an empty student list

void addStudent(StudentList *list, const char *name, float score) {
    if(list->count >= MAX_STUDENTS) {
        printf("Maximum capacity reached\n");
        return;
    }

    Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.score = score;

    list->students[list->count++] = newStudent;
}
// Adds a student to the end of the array

void deleteStudent(StudentList *list, int index) {
    if(list->count == 0) {
        printf("There are no students\n");
        return;
    }

    for(int i = index; i < list->count; list->students[i] = list->students[i + 1], i++) {}
    list->count--;
}
// Deletes student at a given index (0-based)

void displayStudents(StudentList list) {
    if(list.count == 0) {
        printf("empty\n");
        return;
    }

    for(int i = 0; i < list.count; i++) printf("[%d] %s - %.1f\n", i, list.students[i].name, list.students[i].score);
    printf("\n");
}
// Displays all students in the list

Student findTopScorer(StudentList list) {
    Student none = {"", 0};
    if(list.count == 0) {
        printf("Empty list\n");
        return none;
    }

    Student max = list.students[0];
    for(int i = 0; i < list.count; i++) {
        if(list.students[i].score > max.score) {
            max = list.students[i];
        }
    }
    return max;
}
// Returns the student with the highest score

int main() {
    StudentList list;
    initStudentList(&list);

    addStudent(&list, "Anna", 88.5);
    addStudent(&list, "Brian", 92.0);
    addStudent(&list, "Chloe", 79.3);

    puts("Initial Students:");
    displayStudents(list);

    printf("\nDeleting student at index 1...\n");
    deleteStudent(&list, 1);

    puts("After Deletion:");
    displayStudents(list);

    Student top = findTopScorer(list);
    printf("\nTop Scorer: %s with %.1f\n", top.name, top.score);

    return 0;
}

/*
Initial Students:
[0] Anna - 88.5
[1] Brian - 92.0
[2] Chloe - 79.3

Deleting student at index 1...
After Deletion:
[0] Anna - 88.5
[1] Chloe - 79.3

Top Scorer: Anna with 88.5
*/