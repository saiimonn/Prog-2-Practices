#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
typedef struct {
    int employee_id;
    char name[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee(Employee **employees, int *size, int *capacity);
void updateSalary(Employee *employees, int size);
void removeEmployee(Employee **employees, int *size);
void displayEmployees(Employee *employees, int size);
void freeEmployees(Employee *employees);

int main() {
    Employee *employees = NULL;
    int size = 0;
    int capacity = 0;
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Update Employee Salary\n");
        printf("3. Remove an Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                addEmployee(&employees, &size, &capacity);
                break;
            case 2:
                updateSalary(employees, size);
                break;
            case 3:
                removeEmployee(&employees, &size);
                break;
            case 4:
                displayEmployees(employees, size);
                break;
            case 5:
                printf("Exiting program...\n");
                freeEmployees(employees);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new employee
void addEmployee(Employee **employees, int *size, int *capacity) {
    // ADD CODE HERE...
    if(*size == *capacity) {
        *capacity = (*capacity == 0) ? 1 : *capacity * 2;
        *employees = realloc(*employees, *capacity * sizeof(Employee));
    }

    Employee newEmployee;
    printf("\nEnter Employee ID: ");
    scanf("%d", &newEmployee.employee_id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", newEmployee.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &newEmployee.salary);

    (*employees)[*size] = newEmployee;
    (*size)++;
    printf("Employee added successfully!\n");
}

// Function to update salary
void updateSalary(Employee *employees, int size) {
    // ADD CODE HERE...
    int id;
    printf("Enter Employee ID to update salary: ");
    scanf("%d", &id);

    float newSalary;
    printf("Enter new salary: ");
    scanf("%f", &newSalary);

    for(int i = 0; i < size; i++) {
        if(employees[i].employee_id == id) {
            employees[i].salary = newSalary;
            printf("Salary updated successfully!\n");
            return;
        }
    }

    printf("Employee ID not found.\n");
}

// Function to remove an employee
void removeEmployee(Employee **employees, int *size) {
    // ADD CODE HERE...
    int id;
    printf("Enter Employee ID to remove: ");
    scanf("%d", &id);

    for(int i = 0; i < *size; i++) {
        if(employees[i]->employee_id == id) {
            for(int j = i; j < *size; j++) {
                (*employees)[j] = (*employees)[j + 1];
            }
            (*size)--;
            *employees = realloc(*employees, (*size) * sizeof(Employee));
            printf("Employee removed successfully!\n");
            return;
        }
    }
    printf("Employee ID not found.\n");
}

// Function to display all employees sorted by salary
void displayEmployees(Employee *employees, int size) {
    // ADD CODE HERE...
    if(size == 0) {
        printf("No employees to display.\n");
        return;
    }

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(employees[j].salary > employees[j + 1].salary) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("\nEmployee List (Sorted by Salary):\n");
    printf("ID\tName\t\tSalary\n");
    printf("---------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%-15s\t%.2f\n", employees[i].employee_id, employees[i].name, employees[i].salary);
    }
}

// Function to free allocated memory
void freeEmployees(Employee *employees) {
    // ADD CODE HERE...
    free(employees);
}