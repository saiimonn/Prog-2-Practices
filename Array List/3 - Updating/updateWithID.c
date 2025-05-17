//Update the salary of an employee with emp_id x
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int emp_id;
    float salary;
    char name[50];
} Employee;

typedef struct {
    Employee employees[MAX];
    int count;
} List;

void insert(List *list, int id, float salary, const char *name) {
    if(list->count >= MAX) {
        printf("List is at maximum capacity\n");
        return;
    }

    int idx;
    for(idx = 0; idx < list->count && list->employees[idx].salary <= salary; idx++) {}

    for(int i = list->count; i > idx; list->employees[i] = list->employees[i - 1], i--) {}

    list->employees[idx].emp_id = id;
    list->employees[idx].salary = salary;
    strcpy(list->employees[idx].name, name);
    list->count++;
}

void displayList(List list) {
    if(list.count == 0) {
        printf("List is empty\n");
        return;
    }

    printf("EMPLOYEE LIST:\n");
    for(int i = 0; i < list.count; i++) printf("{ID: %d, Name: %s, Salary: %.2f}\n", list.employees[i].emp_id, list.employees[i].name, list.employees[i].salary);
    printf("\n");
}

void updateSalary(List *list, int id, int newSalary) {
    if(list->count == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < list->count; i++) {
        if(list->employees[i].emp_id == id) {
            list->employees[i].salary = newSalary;
            printf("Employee with ID %d salary updated\n", id);
            return;
        }
    }
    printf("Employee with ID %d not found\n", id);
}

int main() {
    List empList = {.count = 0};

    insert(&empList, 101, 48000.00, "Alice");
    insert(&empList, 102, 52000.00, "Bob");
    insert(&empList, 103, 45000.00, "Charlie");

    printf("Before salary update:\n");
    displayList(empList);

    updateSalary(&empList, 102, 60000.00);

    printf("\nAfter salary update:\n");
    displayList(empList);

    return 0;
}