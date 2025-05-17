/* ---- Car Rental Tracker ----------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 15
typedef enum { AVAILABLE, RENTED } CarStatus;

/* fixed-array element */
typedef struct {
    char plate[10];
    char model[30];
    int  year;
    CarStatus status;
} Car;

/* singly-linked-list node for RENTED cars */
typedef struct CarNode {
    Car data;
    struct CarNode *next;
} *CarList;

/* whole database */
typedef struct {
    Car cars[MAX_CARS];  /* original array */
    int total;
    CarList rentedList;  /* linked list for RENTED cars */
} Fleet;

/* ------------ prototypes you must implement ---------------- */
void initFleet(Fleet *f) {
    f->total = 8;
    f->rentedList = NULL;

    Car preload[] = {
        {"AAA111", "Corolla",  2018, AVAILABLE},
        {"XYZ123", "Civic",    2019, AVAILABLE},
        {"CAR007", "Fortuner", 2021, RENTED},
        {"JEE888", "Wrangler", 2020, RENTED},
        {"TES333", "Model 3",  2022, AVAILABLE},
        {"VAN555", "HiAce",    2017, AVAILABLE},
        {"SUV222", "Rav4",     2020, RENTED},
        {"MIN999", "Mini",     2016, AVAILABLE}
    };
    memcpy(f->cars, preload, f->total * sizeof(Car));

} /* preload 8 cars */

void populateRentedList(Fleet *f) {
    for(int i = 0; i < f->total; i++) {
        CarList newNode = malloc(sizeof(struct CarNode));
        if(!newNode) exit(0);

        if(f->cars[i].status == RENTED) {
            newNode->data = f->cars[i];
            newNode->next = f->rentedList;
            f->rentedList = newNode;
        }
    }
    printf("Rented cars moved to Linked List\n");
} /* move RENTED into LL */

void rentCar(Fleet *f, const char *plate) {
    if(f->total == 0) {
        printf("No cars\n");
        return;
    }

    for(int i = 0; i < f->total; i++) {
        if(strcmp(f->cars[i].plate, plate) == 0) {
            f->cars[i].status = RENTED;

            CarList newNode = malloc(sizeof(struct CarNode));
            if(!newNode) exit(0);

            newNode->data = f->cars[i];
            newNode->next = f->rentedList;
            f->rentedList = newNode;

            printf("Car with plate no. %s is now rented.\n", plate);
            return;
        }
    }
    printf("Car with plate no. %s does not exist.\n", plate);
} /* set status + add to LL */

void returnCar(Fleet *f, const char *plate) {
    if(f->total == 0 || f->rentedList == NULL) {
        printf("Empty\n");
        return;
    }

    int found = 0;
    for(int i = 0; i < f->total; i++) {
        if(strcmp(f->cars[i].plate, plate) == 0) {
            f->cars[i].status = AVAILABLE;
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Car with plate %s does not exist\n", plate);
        return;
    }

    CarList *indirect = &f->rentedList;
    while(*indirect != NULL) {
        if(strcmp((*indirect)->data.plate, plate) == 0) {
            CarList temp = *indirect;
            *indirect = (*indirect)->next;
            free(temp);
            printf("Car with plate no. %s is now available and is removed from linked list\n", plate);
        }
    }
}  /* set status + remove LL */

void showAvailableArray(Fleet f) {
    if(f.total == 0) {
        printf("empty\n");
        return;
    }

    printf("AVAILABLE CARS:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-30s %-6s %-10s\n", "PLATE", "MODEL", "YEAR", "STATUS");

    for(int i = 0; i < f.total; i++) {
        if(f.cars[i].status == AVAILABLE) {
            printf("%-20s %-30s %-6d %-10s\n", f.cars[i].plate, f.cars[i].model, f.cars[i].year, "AVAILABLE");
        }
    }
    printf("\n");
} /* array display */

void showRentedList(CarList head) {
    if(!head) {
        printf("Empty\n");
        return;
    }

    printf("RENTED CARS:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-20s %-30s %-6s %-10s\n", "PLATE", "MODEL", "YEAR", "STATUS");

    CarList ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%-20s %-30s %-6d %-10s\n", 
            ptr->data.plate, ptr->data.model, 
            ptr->data.year, 
            "RENTED");
    }
    printf("\n");
} /* LL display */

void freeCarList(CarList head) {
    CarList temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
} /* free memory */

/* ------------------ main: demo run -------------------------- */
int main(void){
    Fleet fl; initFleet(&fl);
    populateRentedList(&fl);

    puts("\nInitial state:");
    showAvailableArray(fl);   showRentedList(fl.rentedList);

    puts("\nCustomer rents plate XYZ123:");
    rentCar(&fl,"XYZ123");
    showAvailableArray(fl);   showRentedList(fl.rentedList);

    puts("\nCustomer returns plate CAR007:");
    returnCar(&fl,"CAR007");
    showAvailableArray(fl);   showRentedList(fl.rentedList);

    freeCarList(fl.rentedList);
    return 0;
}
/* ------ Expected sample output (abbrev) ----------------------
Initial state:
AVAILABLE CARS
Plate  Model               Year
AAA111 Corolla             2018
XYZ123 Civic               2019
...
RENTED CARS
Plate  Model               Year
CAR007 Fortuner            2021
...
Customer rents plate XYZ123:
...
Customer returns plate CAR007:
...
-------------------------------------------------------------- */