/* ---- Hospital Triage ------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAT 25
typedef enum { CRITICAL, STABLE } Condition;

typedef struct{
    int  id;
    char name[30];
    Condition cond;
} Patient;

typedef struct PNode{
    Patient data;
    struct PNode *next;
} *PatList;

typedef struct{
    Patient roster[MAX_PAT];
    int total;
    PatList criticalList;   /* linked list of CRITICAL patients */
} Ward;

/* --------- prototypes to implement ---------- */
void initWard(Ward *w)
{
    w->total = 10;
    w->criticalList = NULL;

    Patient preload[] = {
        {101, "Alice",     CRITICAL},
        {102, "Bob",       STABLE},
        {103, "Charlie",   CRITICAL},
        {104, "Diana",     STABLE},
        {105, "Ethan",     CRITICAL},
        {106, "Fiona",     STABLE},
        {107, "George",    CRITICAL},
        {108, "Hannah",    STABLE},
        {109, "Ivan",      STABLE},
        {110, "Julia",     CRITICAL}
    };
    memcpy(w->roster, preload, w->total * sizeof(Patient));
}                     /* preload 10 patients */

void buildCriticalList(Ward *w) {
    if(w->total == 0) {
        printf("List is empty\n");
        return;
    }

    for(int i = 0; i < w->total; i++) {
        PatList newNode = malloc(sizeof(struct PNode));
        if(!newNode) exit(0);

        if(w->roster[i].cond == CRITICAL) {
            newNode->data = w->roster[i];
            newNode->next = w->criticalList;
            w->criticalList = newNode;
        }
    }
    printf("Patients with Critical condition successfully added to linked list\n");
}              /* array → LL */

Patient *getStableArray(Ward *w,int *cnt) {
    if(w->total == 0) {
        printf("List is empty\n");
        return NULL;
    }

    for(int i = 0; i < w->total; i++) {
        if(w->roster[i].cond == STABLE) {
            (*cnt)++;
        }
    }

    if(*cnt == 0) {
        printf("There are no patients with a stable conditon\n");
        return NULL;
    }

    Patient *stableArr = malloc(sizeof((*cnt) * sizeof(Patient)));
    int idx = 0;
    for(int i = 0; i < w->total; i++) {
        if(w->roster[i].cond == STABLE) {
            stableArr[idx++] = w->roster[i];
        }
    }
    printf("Patients with Stable condition successfully added to array list\n");
    return stableArr;
}    /* dyn array of STABLE */

void showCritical(PatList head) {
    if(!head) {
        printf("List is empty\n");
        return;
    }

    printf("CRITICAL PATIENTS:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-30s %-10s\n", "ID", "NAME", "CONDITION");
    printf("-------------------------------------------------------------\n");

    for(PatList ptr = head; ptr != NULL; ptr = ptr->next) printf("%-20d %-30s %-10s\n", ptr->data.id, ptr->data.name, "CRITICAL");
    printf("\n");
}

void showStable(Patient arr[],int cnt) {
    if(cnt == 0) {
        printf("List is empty\n");
        return;
    }

    printf("STABLE PATIENTS:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-30s %-10s\n", "ID", "NAME", "CONDITION");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < cnt; i++) printf("%-20d %-30s %-10s\n", arr[i].id, arr[i].name, "STABLE");
}

void freePL(PatList head) {
    PatList temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ------------- main demo -------------------- */
int main(void){
    Ward ward; initWard(&ward);
    buildCriticalList(&ward);

    int stableCnt=0;
    Patient *stable = getStableArray(&ward,&stableCnt);

    puts("\nCRITICAL patients (LL):");
    showCritical(ward.criticalList);

    puts("\nSTABLE patients (Array):");
    showStable(stable,stableCnt);

    free(stable); freePL(ward.criticalList);
    return 0;
}
/* Expected: two tables, one from LL (critical) and one from array (stable) */