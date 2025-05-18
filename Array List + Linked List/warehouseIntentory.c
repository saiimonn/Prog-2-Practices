/* ---- Warehouse Inventory -------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 30
typedef enum { IN_STOCK, RESERVED } StockStatus;

typedef struct{
    char sku[12];
    char desc[40];
    int  qty;
    StockStatus stat;
} Item;

typedef struct INode{
    Item data;
    struct INode *next;
} *ReservedList;

typedef struct{
    Item items[MAX_ITEMS];
    int total;
    ReservedList head;      /* linked list of RESERVED items */
} Warehouse;

/* prototypes */
void initWarehouse(Warehouse *w)
{
    w->total = 10;
    w->head = NULL;

    Item preload[] = {
        {"A12", "Steel Bolts",          50, IN_STOCK},
        {"B77", "Copper Wire Roll",     20, RESERVED},
        {"C09", "PVC Pipe (2 m)",       40, IN_STOCK},
        {"D45", "Aluminium Sheet",      15, RESERVED},
        {"E31", "LED Panel Light",      60, IN_STOCK},
        {"F83", "Circuit Breaker 30 A", 35, IN_STOCK},
        {"G56", "HD Drill Bits Set",    25, RESERVED},
        {"H18", "Safety Gloves Box",    80, IN_STOCK},
        {"J24", "Paint (White 1 L)",    45, IN_STOCK},
        {"K60", "Rubber Gasket Kit",    30, RESERVED}
    };
    memcpy(w->items, preload, w->total * sizeof(Item));
}          /* preload */

void buildReservedList(Warehouse *w) {
    if(w->total == 0) {
        printf("Inventory is empty\n");
        return;
    }

    for(int i = 0; i < w->total; i++) {
        ReservedList newNode = malloc(sizeof(struct INode));
        if(!newNode) exit(0);

        if(w->items[i].stat == RESERVED) {
            newNode->data = w->items[i];
            newNode->next = NULL;

            if(w->head == NULL) {
                w->head = newNode;
            } else {
                ReservedList temp;
                for(temp = w->head; temp->next != NULL; temp = temp->next) {}
                temp->next = newNode;
            }
        }
    }
    printf("Items with status 'RESERVED' successfully added to Linked List\n");
}     /* to LL */

void reserveItem(Warehouse *w,const char *sku,int qty) {
    if(w->total == 0) {
        printf("Empty\n");
        return;
    }

    int i;
    for(i = 0; i < w->total; i++) {
        if(strcmp(w->items[i].sku, sku) == 0 && w->items[i].stat == IN_STOCK) {
            if(w->items[i].qty < qty) {
                printf("Not enuf stock\n");
                return;
            }

            ReservedList trav;
            for(trav = w->head; trav != NULL; trav = trav->next) {
                if(strcmp(trav->data.sku, sku) == 0) {
                    trav->data.qty += qty;
                    w->items[i].qty -= qty;
                    printf("%d items reserved\n", qty);
                    return;
                }
            }

            ReservedList newNode = malloc(sizeof(struct INode));
            if(!newNode) exit(0);

            newNode->data = w->items[i];
            newNode->data.stat = RESERVED;
            newNode->data.qty = qty;
            newNode->next = w->head;
            w->head = newNode;
            w->items[i].qty -= qty;

            printf("%d items reserved\n", qty);
            return;
        }
    }
    printf("Item not found\n");
} /* adjust qty / move node */

void releaseItem(Warehouse *w,const char *sku) {
    if(!w->head) {
        printf("Empty\n");
        return;
    }

    ReservedList prev = NULL, curr = w->head;
    while(curr != NULL) {
        if(strcmp(curr->data.sku, sku) == 0) {
            for(int i = 0; i < w->total; i++) {
                if(strcmp(w->items[i].sku, sku) == 0) {
                    w->items[i].qty += curr->data.qty;
                    break;
                }
            }

            if(prev == NULL) {
                w->head = curr->next;
            } else {
                prev->next = curr->next;
            }

            free(curr);
            return;
        } 

        prev = curr;
        curr = curr->next;
    }
}         /* remove node / adjust qty */

void showStock(Warehouse w) {
    if(w.total == 0) {
        printf("empty\n");
        return;
    }

    printf("ITEMS IN STOCK:\n");
    printf("----------------------------------------------------------------------------\n");
    printf("%-20s %-30s %-15s %-15s\n", "SKU", "DESCRIPTION", "QUANTITY", "STATUS");
    printf("----------------------------------------------------------------------------\n");

    for(int i = 0; i < w.total; i++) printf("%-20s %-30s %-15d %-15s\n", w.items[i].sku, w.items[i].desc, w.items[i].qty, (w.items[i].stat == IN_STOCK) ? "IN_STOCK" : "RESERVED");
    printf("\n");
}

void showReserved(ReservedList head) {
    if(!head) {
        printf("empty\n");
        return;
    }

    printf("ITEMS RESERVED:\n");
    printf("----------------------------------------------------------------------------\n");
    printf("%-20s %-30s %-15s %-15s\n", "SKU", "DESCRIPTION", "QUANTITY", "STATUS");
    printf("----------------------------------------------------------------------------\n");

    for(ReservedList ptr = head; ptr != NULL; ptr = ptr->next) printf("%-20s %-30s %-15d %-15s\n", ptr->data.sku, ptr->data.desc, ptr->data.qty, (ptr->data.stat == IN_STOCK) ? "IN_STOCK" : "RESERVED");
    printf("\n");
}

void freeRL(ReservedList head) {
    ReservedList temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void){
    Warehouse wh; initWarehouse(&wh);
    buildReservedList(&wh);

    puts("Initial:");
    showStock(wh); showReserved(wh.head);

    puts("\nReserve SKU A12 for 5 units:");
    reserveItem(&wh,"A12",5);
    showStock(wh); showReserved(wh.head);

    puts("\nRelease SKU B77:");
    releaseItem(&wh,"B77");
    showStock(wh); showReserved(wh.head);

    freeRL(wh.head);
    return 0;
}