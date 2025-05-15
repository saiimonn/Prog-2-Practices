## Employee Management Using Dynamic Arrays (C Programming)
## by Christine Bandalan

Write a C program that manages a list of employees using a dynamic array (similar to an ArrayList). The program should present a menu that allows the user to perform the following operations:

Add an Employee. Add a new employee to the end of the array. Each employee should have:
An integer employee_id
A character array name[50]
A float salary
Update Employee Salary. Update the salary of an existing employee by searching for their employee_id.
Remove an Employee. Remove an employee from the array by their employee_id. After removal, shift the remaining employees to fill the gap.
Display All Employees. Print the list of all employees, showing their employee_id, name, and salary. Use bubble sort to order employees by salary in ascending order.
 
## Requirements:
Define a struct to represent an employee.
Manage the dynamic array manually using malloc, realloc, and free.
Handle memory properly after adding or removing employees.
Design a user-friendly menu for interaction.