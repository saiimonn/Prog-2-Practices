#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char condition[100];
} Patient;

typedef struct node {
    Patient data;
    struct node *next;
} PatientNode;

void registerPatient(PatientNode **head, Patient p) {
    PatientNode *newNode = malloc(sizeof(PatientNode));
    newNode->data = p;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    PatientNode *ptr;
    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = newNode;
}

void dischargePatient(PatientNode **head, int id) {
    if(*head == NULL) {
        printf("Empty list\n");
        return;
    }

    PatientNode *temp;
    if((*head)->data.id == id) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    PatientNode *prev;
    for(temp = *head, prev = NULL; temp != NULL && temp->data.id != id; prev = temp, temp = temp->data.id) {}

    if(temp == NULL) {
        printf("ID doesn't exist\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

Patient* findPatientByCondition(PatientNode *head, const char *condition) {
    
}

void displayPatients(PatientNode *head) {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }

    PatientNode *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("{%d, %s, %d, %s} -> ", ptr->data.id, ptr->data.name, ptr->data.age, ptr->data.condition);
    printf("NULL\n");
}

int main() {
    PatientNode *patients = NULL;

    Patient p1 = {1, "Anna", 25, "Flu"};
    Patient p2 = {2, "Mark", 40, "Fracture"};
    Patient p3 = {3, "Lucy", 30, "Flu"};

    registerPatient(&patients, p1);
    registerPatient(&patients, p2);
    registerPatient(&patients, p3);

    displayPatients(patients);

    printf("\nDischarging patient with ID 2...\n");
    dischargePatient(&patients, 2);

    displayPatients(patients);

    Patient *found = findPatientByCondition(patients, "Flu");
    if (found) {
        printf("\nFound Patient: %s (Condition: %s)\n", found->name, found->condition);
        free(found);
    }

    return 0;
}