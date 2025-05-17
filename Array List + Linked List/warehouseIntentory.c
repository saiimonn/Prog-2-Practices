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
    ReservedList reserved;      /* linked list of RESERVED items */
} Warehouse;

/* prototypes */
void initWarehouse(Warehouse *w)
{
    w->total = 10;
    w->reserved = NULL;

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

void buildReservedList(Warehouse *w);      /* to LL */
void reserveItem(Warehouse *w,const char *sku,int qty); /* adjust qty / move node */
void releaseItem(Warehouse *w,const char *sku);         /* remove node / adjust qty */
void showStock(Warehouse w);
void showReserved(ReservedList head);
void freeRL(ReservedList head);

int main(void){
    Warehouse wh; initWarehouse(&wh);
    buildReservedList(&wh);

    puts("Initial:");
    showStock(wh); showReserved(wh.reserved);

    puts("\nReserve SKU A12 for 5 units:");
    reserveItem(&wh,"A12",5);
    showStock(wh); showReserved(wh.reserved);

    puts("\nRelease SKU B77:");
    releaseItem(&wh,"B77");
    showStock(wh); showReserved(wh.reserved);

    freeRL(wh.reserved);
    return 0;
}