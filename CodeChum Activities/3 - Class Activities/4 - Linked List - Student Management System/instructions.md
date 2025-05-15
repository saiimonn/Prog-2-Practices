## Linked List - Student Management System
## by Edwin Bartlett

**Student* createStudent(char name[], int studentID, float gpa):**
This function allocates memory for a new Student structure.

**Student* insertStudent(Student* head, char name[], int studentID, float gpa):**
This function creates a new student node by calling createStudent().
It inserts the new student node at the beginning of the linked list.

**Student* deleteStudent(Student* head, int studentID):**
This function removes a student from the linked list based on the provided studentID.

**void displayStudents(Student* head):**
This function iterates through the linked list and prints the details (name, ID, and GPA) of each student.

**void searchStudentByName(Student* head, char searchName[]):**
This function searches the linked list for students with a name matching the provided searchName.

**void freeList(Student* head):**
This function iterates through the linked list, freeing the memory allocated for each student node to prevent memory leaks.