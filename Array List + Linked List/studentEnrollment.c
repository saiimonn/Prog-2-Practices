#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20
typedef enum { ENROLLED, WAITLISTED } Status;

typedef struct {
    char id[10];
    char name[30];
    Status stat;
} Student;

typedef struct node {
    Student data;
    struct node *next;
} *Waitlist;

typedef struct {
    Student students[MAX_STUDENTS];
    int total;
    Waitlist waitHead;
} Enrollment;

void initEnrollment(Enrollment *e) {
    e->total = 6;
    e->waitHead = NULL;

    Student preload[] = {
        {"S01", "Alice", ENROLLED},
        {"S02", "Bob", WAITLISTED},
        {"S03", "Cathy", ENROLLED},
        {"S04", "Dave", WAITLISTED},
        {"S05", "Eva", ENROLLED},
        {"S06", "Finn", WAITLISTED}
    };
    memcpy(e->students, preload, e->total * sizeof(Student));
}

void buildWaitlist(Enrollment *e) {
    if(e->total == 0) {
        printf("No students\n");
        return;
    }

    for(int i = 0; i < e->total; i++) {
        Waitlist newNode = malloc(sizeof(struct node));
        if(!newNode) exit(0);

        if(e->students[i].stat == WAITLISTED) {
            newNode->data = e->students[i];
            newNode->next = e->waitHead;
            e->waitHead = newNode;
        }
    }
    printf("All waitlisted students added to linked list\n");
} //move WAITLISTED students to LL

void enrollStudent(Enrollment *e, const char *id) {
    if(e->total == 0 || e->waitHead == NULL) {
        printf("empty\n");
        return;
    }

    int isFound = 0;
    for(int i = 0; i < e->total; i++) {
        if(strcmp(e->students[i].id, id) == 0) {
            e->students[i].stat = ENROLLED;
            isFound = 1;
            break;
        }
    }

    if(!isFound) return;

    Waitlist *indirect = &e->waitHead;
    while(*indirect != NULL) {
        if(strcmp((*indirect)->data.id, id) == 0) {
            Waitlist temp = *indirect;
            *indirect = (*indirect)->next;
            free(temp);
        }
    }
} //change status, remove from waitlist

void dropStudent(Enrollment *e, const char *id) {
    if(e->total == 0) {
        printf("empty\n");
        return;
    }

    for(int i = 0; i < e->total; i++) {
        if(strcmp(e->students[i].id, id) == 0) {
            e->students[i].stat = WAITLISTED;

            Waitlist newNode = malloc(sizeof(struct node));
            if(!newNode) exit(0);

            newNode->data = e->students[i];
            newNode->next = e->waitHead;
            e->waitHead = newNode;
            printf("Student status now changed to waitlisted\n");
            return;
        }
    }
    printf("Student not found\n");
} //change status to WAITLISTED and move to LL

void showAll(Enrollment e) {
    if(e.total == 0) return;

    printf("STUDENT LIST:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-15s %-30s %-15s\n", "ID", "NAME", "STATUS");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < e.total; i++) printf("%-15s %-30s %-15s\n", e.students[i].id, e.students[i].name, (e.students[i].stat == WAITLISTED) ? "WAITLISTED" : "ENROLLED");
    printf("\n");
} //display array contents

void showWaitlist(Waitlist head) {
    if(!head) return;

    printf("STUDENT WAITLIST:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-15s %-30s %-15s\n", "ID", "NAME", "STATUS");
    printf("-------------------------------------------------------------\n");

    for(Waitlist ptr = head; ptr != NULL; ptr = ptr->next) printf("%-15s %-30s %-15s\n", ptr->data.id, ptr->data.name, "WAITLISTED");
    printf("\n");
} //display LL contents

void freeWaitlist(Waitlist head) {
    if(!head) return;
    Waitlist temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
} //deallocate memory

int main(void) {
    Enrollment e;
    initEnrollment(&e);
    buildWaitlist(&e);

    puts("INITIAL DATA:");
    showAll(e);
    showWaitlist(e.waitHead);

    puts("\nEnrolling student S02...");
    enrollStudent(&e, "S02");
    showAll(e);
    showWaitlist(e.waitHead);

    puts("\nDropping student S03...");
    dropStudent(&e, "S03");
    showAll(e);
    showWaitlist(e.waitHead);

    freeWaitlist(e.waitHead);
    return 0;
}