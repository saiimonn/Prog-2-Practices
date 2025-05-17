#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_STUDENTS 50

typedef struct {
    char name[MAX_NAME];
    float gpa;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} StudentList;

// Function declarations
void addStudent(StudentList *list, Student s) {
    if(list->count >= MAX_STUDENTS) {
        printf("List is already full\n");
        return;
    }

    for(int i = list->count; i > 0; i--) {
        list->students[i] = list->students[i - 1];
    }

    list->students[0] = s;
    list->count++;
    printf("Student added successfully\n");
}

void removeStudent(StudentList *list, const char *name) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->students[i].name, name) == 0) {
            for(int j = i; j < list->count - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->count--;
            printf("Student removed successfully\n");
            return;
        }
    }
}

float computeAverageGPA(StudentList list) {
    if(list.count == 0) {
        printf("List empty\n");
        return 0;
    }

    float sum = 0;
    for(int i = 0; i < list.count; i++) {
        sum += list.students[i].gpa;
    }

    return sum / list.count;
}

Student getTopStudent(StudentList list) {
    if(list.count == 0) {
        printf("List empty\n");
    }

    Student top = list.students[0];

    for(int i = 1; i < list.count; i++) {
        if(list.students[i].gpa > top.gpa) {
            top = list.students[i];
        }
    }
    return top;
}

void displayAll(StudentList list) {
    if(list.count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list.count; i++) printf("Student Name: %s, Student GPA: %.2f\n", list.students[i].name, list.students[i].gpa);
}

int main() {
    StudentList slist = {.count = 0};

    addStudent(&slist, (Student){"Alice", 3.5});
    addStudent(&slist, (Student){"Bob", 3.8});
    addStudent(&slist, (Student){"Charlie", 3.2});

    displayAll(slist);
    printf("Average GPA: %.2f\n", computeAverageGPA(slist));

    Student top = getTopStudent(slist);
    printf("Top Student: %s (%.2f GPA)\n", top.name, top.gpa);

    removeStudent(&slist, "Bob");
    displayAll(slist);

    return 0;
}