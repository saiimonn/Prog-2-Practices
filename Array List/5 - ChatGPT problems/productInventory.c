#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 30

typedef struct {
    char code[10];
    char description[40];
    int stock;
} Product;

typedef struct {
    Product items[MAX_PRODUCTS];
    int total;
} Inventory;

void initInventory(Inventory *inv) {
    inv->total = 5;
    Product preload[] = {
        {"P01", "Hammer", 15},
        {"P02", "Screwdriver", 30},
        {"P03", "Wrench", 25},
        {"P04", "Pliers", 20},
        {"P05", "Drill", 10}
    };
    memcpy(inv->items, preload, inv->total * sizeof(Product));
}
// Initializes inventory with 5 preloaded items

void addProduct(Inventory *inv, const char *code, const char *desc, int stock) {
    if(inv->total >= MAX_PRODUCTS) return;

    Product newProduct;
    strcpy(newProduct.code, code);
    strcpy(newProduct.description, desc);
    newProduct.stock = stock;

    inv->items[inv->total++] = newProduct;
}
// Adds a new product to the array

void updateStock(Inventory *inv, const char *code, int change) {
    if(inv->total == 0) return;

    for(int i = 0; i < inv->total; i++) {
        if(strcmp(inv->items[i].code, code) == 0) {
            inv->items[i].stock += change;
            return;
        }
    }
    printf("Not found\n");
}
// Updates the stock quantity by `change` (can be + or -)

void searchProduct(Inventory inv, const char *code) {
    if(inv.total == 0) return;

    for(int i = 0; i < inv.total; i++) {
        if(strcmp(inv.items[i].code, code) == 0) {
            printf("Found: %s, Stock: %d\n", inv.items[i].description, inv.items[i].stock);
            return;
        }
    }
    printf("Item not found\n");
}
// Displays product info if found

void displayInventory(Inventory inv) {
    if(inv.total == 0) return;

    for(int i = 0; i < inv.total; i++) printf("[%s] %s - %d\n", inv.items[i].code, inv.items[i].description, inv.items[i].stock);
    printf("\n");
}
// Prints all products in inventory

int main() {
    Inventory inv;
    initInventory(&inv);

    puts("Initial Inventory:");
    displayInventory(inv);

    puts("\nAdding new product...");
    addProduct(&inv, "P66", "Extension Wire", 20);
    displayInventory(inv);

    puts("\nUpdating stock for code 'P66'...");
    updateStock(&inv, "P66", -5);
    displayInventory(inv);

    puts("\nSearching for 'P66'...");
    searchProduct(inv, "P66");

    return 0;
}

/*
Initial Inventory:
[P01] Hammer - 15
[P02] Screwdriver - 30
[P03] Wrench - 25
[P04] Pliers - 20
[P05] Drill - 10

Adding new product...
[P01] Hammer - 15
[P02] Screwdriver - 30
[P03] Wrench - 25
[P04] Pliers - 20
[P05] Drill - 10
[P66] Extension Wire - 20

Updating stock for code 'P66'...
[P01] Hammer - 15
...
[P66] Extension Wire - 15

Searching for 'P66'...
Found: Extension Wire, Stock: 15
*/