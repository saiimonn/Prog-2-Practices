#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { PASS, FAIL } Status;

typedef struct name {
    char fName[20];
    char lName[20];
} Name;

typedef struct education {
    char studentId[20];
    Status studentStatus;
    int studentYearLevel; // 1,2,3,4
    float grade;
} Education;

// LINKED LIST representation of Students
typedef struct node {
    Name nameInfo;
    Education educationInfo;
    struct node *link;
} *StudentPTR;

// ARRAY LIST representation of Students
typedef struct student {
    Name nameInfo;
    Education educationInfo;
} Student;

typedef struct data {
    Student students[20];
    StudentPTR head;
    int arrayCount; // Represents the total count of students in an array
    int LLCount;    // Represents the total count of students in a linked list
} Database;

// Initializes the necessary variables and pre-populates the students array.
// THIS IS ANSWERED FOR YOU, SO DON'T MODIFY IT.
void initialize(Database *main);

// Takes data from the Database array and populates the head of the Database
void populateLinkedList(Database *main);

// Simply traverses through a list of students and returns the total count of
// failed students
// THIS IS ANSWERED FOR YOU, SO DON'T MODIFY IT.
int getFailedStudentsCount(Student *students, int count);

// Traverses through the linked lists while transferring failed students over to
// a newly dynamically allocated array.
Student *getFailedStudents(Database *main);

// Displays an array of FAILED students.
// THIS IS PARTIALLY ANSWERED FOR YOU.
void displayArray(Student data[], int count);

// Displays a linked list of PASSED students.
// THIS IS PARTIALLY ANSWERED FOR YOU.
void displayLinkedList(StudentPTR head);

int main() {
    // Declare a variable with data type "Database"
    // Call the initialize() function
    Database db;
    initialize(&db);

    // Problem 1
    // Call populateLinkedList() function
    populateLinkedList(&db);
    Student *failed = NULL;
    failed = getFailedStudents(&db);
    // Problem 2
    // Declare a DYNAMIC array with data type "Student" and set it to NULL
    // Call getFailedStudents() function. Tip: You might want to use
    // getFailedStudentsCount() aux function

    printf("\n\n");

    // Problem 3
    // Display ARRAY
    displayArray(failed, getFailedStudentsCount(db.students, db.arrayCount));
    printf("\n\n");
    displayLinkedList(db.head);
}

void initialize(Database *main) {
    main->arrayCount = 20;
    main->LLCount = 0;
    main->head = NULL;
    Student students[20] = {
        {{"Akeah", "Diez"}, {"2024001", PASS, 1, 1.75}},
        {{"Van", "Pesidas"}, {"2024002", PASS, 2, 2.00}},
        {{"Andre", "Siaton"}, {"2024003", FAIL, 3, 4.25}},
        {{"Justine", "Lequigan"}, {"2024004", PASS, 1, 1.50}},
        {{"Tamayo", "Maruyama"}, {"2024005", PASS, 4, 2.25}},
        {{"Yza", "Alagon"}, {"2024006", FAIL, 2, 3.75}},
        {{"Owen", "Ajero"}, {"2024007", PASS, 1, 1.25}},
        {{"Tricia", "Gubaton"}, {"2024008", PASS, 3, 2.50}},
        {{"Aaron", "Galario"}, {"2024009", FAIL, 2, 3.90}},
        {{"Jared", "Minoza"}, {"2024010", PASS, 4, 1.85}},
        {{"Aldwin", "Fernandez"}, {"2024011", PASS, 3, 2.10}},
        {{"Lana", "Pasculado"}, {"2024012", PASS, 2, 2.00}},
        {{"Wayne", "Ricaplaza"}, {"2024013", FAIL, 1, 4.00}},
        {{"Cliff", "Jao"}, {"2024014", PASS, 2, 1.95}},
        {{"Mauris", "Samson"}, {"2024015", PASS, 4, 2.20}},
        {{"Nicole", "Heredia"}, {"2024016", FAIL, 1, 3.50}},
        {{"Francisco", "Jubelag"}, {"2024017", PASS, 2, 1.70}},
        {{"Jose", "Carumba"}, {"2024018", PASS, 3, 1.60}},
        {{"Carmela", "Suico"}, {"2024019", FAIL, 4, 4.50}},
        {{"John", "Ponce"}, {"2024020", PASS, 2, 2.00}}};

    memcpy(main->students, students, sizeof(students));

    printf("\nInitialized the database.");
}

void populateLinkedList(Database *main) {
    // Start writing your code here
    for(int i = 0; i < main->arrayCount; i++) {
        StudentPTR newNode = malloc(sizeof(struct node));
        if(!newNode) {
            printf("Mem alloc failed\n");
            exit(0);
        }

        newNode->nameInfo = main->students[i].nameInfo;
        newNode->educationInfo = main->students[i].educationInfo;
        newNode->link = main->head;
        main->head = newNode;
        main->LLCount++;
    }
    printf("\nTransferred array elements into linked list.");
}

int getFailedStudentsCount(Student *students, int count) {
    int i;
    int failedStudentsCount = 0;

    for (i = 0; i < count; i++) {
        if (students[i].educationInfo.grade > 3.0) {
            failedStudentsCount++;
        }
    }

    return failedStudentsCount;
}

// Tip: You might want to use getFailedStudentsCount() auxiliary function
Student *getFailedStudents(Database *main) {
    // Start writing your code here
    int count = getFailedStudentsCount(main->students, main->arrayCount);
    Student *failedStudents = (Student*)malloc(count * sizeof(Student));

    int idx = 0;
    for(int i = 0; i < main->arrayCount; i++) {
        if(main->students[i].educationInfo.grade > 3.0) {
            failedStudents[idx++] = main->students[i];
        }
    }
    return failedStudents;
}

void displayArray(Student data[], int count) {
    printf("\nDISPLAYING FAILED STUDENTS THROUGH ARRAY");
    printf("\n-------------------------------------------------------------");
    printf("\n%-10s%-15s%-15s%-10s%-10s", "YEAR LVL", "FIRST NAME", "LAST NAME",
           "GRADE", "STATUS");
    // Start writing your code here
    for(int i = 0; i < count; i++) {
        printf("\n%-10d%-15s%-15s%-.2f%-10s\n",
            data[i].educationInfo.studentYearLevel,
            data[i].nameInfo.fName,
            data[i].nameInfo.lName,
            data[i].educationInfo.grade,
            "FAIL"
        );
    }
}

void displayLinkedList(StudentPTR head) {
    StudentPTR trav;
    printf("\nDISPLAYING PASSED STUDENTS THROUGH LINKED LIST");
    printf("\n-------------------------------------------------------------");
    printf("\n%-10s%-15s%-15s%-10s%-10s", "YEAR LVL", "FIRST NAME", "LAST NAME",
           "GRADE", "STATUS");
    // Start writing your code here
    for(trav = head; trav != NULL; trav = trav->link) {
        printf("\n%-10d%-15s%-15s%-.2f \t%-10s\n",
            trav->educationInfo.studentYearLevel,
            trav->nameInfo.fName,
            trav->nameInfo.lName,
            trav->educationInfo.grade,
            (trav->educationInfo.grade > 3.0) ? "FAIL" : "PASS"
        );
    }
}