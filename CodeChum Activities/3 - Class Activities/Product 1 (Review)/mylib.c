//CODE HERE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

void displayDate(Date d) {
    // 1 - to do code logic here
    if(d.date < 10) printf("0%d ", d.date);
    else printf("%d ", d.date);
    switch(d.month) {
        case 0: printf("Jan "); break;
        case 1: printf("Feb "); break;
        case 2: printf("Mar "); break;
        case 3: printf("Apr "); break;
        case 4: printf("May "); break;
        case 5: printf("Jun "); break;
        case 6: printf("Jul "); break;
        case 7: printf("Aug "); break;
        case 8: printf("Sep "); break;
        case 9: printf("Oct "); break;
        case 10: printf("Nov "); break;
        case 11: printf("Dec "); break;
    }
    printf("%d", d.year);
}

void displayProduct(Product p) {
    // 1 - to do code logic here
    printf("Product ID: %d\nProduct Name: %s\nShelf Life: %d months\n", p.prodID, p.prodName, p.prodShelfLife);
    printf("Manufacturing Date: ");
    displayDate(p.prodMFG);
    printf("\n");
    printf("Quantity: %d", p.prodQty);
}

void displayProducts(ProductList prodList) {
    printf("%-10s | %-25s | %-15s | %-10s | %s\n",
        "ID", "Name", "Shelf Life", "Quantity", "Manufactured Date");

    // 3 - to do code logic here
    for(int i = 0; i < prodList.count; i++) {
        printf("%10d | %-25s | %15d | %10d | ", prodList.prods[i].prodID, prodList.prods[i].prodName, prodList.prods[i].prodShelfLife, prodList.prods[i].prodQty);
        displayDate(prodList.prods[i].prodMFG);
        printf("\n");
    }
}

Date createDate(int date, int month, int year) {
    // 4 - to do code logic here
    Date newDate;
    
    newDate.date = date;
    newDate.month = month;
    newDate.year = year;
    
    return newDate;
}

Product createProduct(int prodID, char prodName[], int prodShelfLife, Date prodMFG, int prodQty) {
    // 5 - to do code logic here
    Product newProduct;
    
    newProduct.prodID = prodID;
    strcpy(newProduct.prodName, prodName);
    newProduct.prodShelfLife = prodShelfLife;
    newProduct.prodMFG = prodMFG;
    newProduct.prodQty = prodQty;
    
    return newProduct;
}

ProductList populateProductList(int option, int count) {
    Product list[20];
    int ctr = 0;
    ProductList prods;

    prods.prods = malloc(sizeof(Product) * count);
    prods.count = 0;
    prods.max = count;

    list[ctr++] = createProduct(1, "BBQ Sauce", 12, createDate(5, 6, 2024), 10);
    list[ctr++] = createProduct(2, "Variental Vinegar", 24, createDate(16, 2, 2023), 17);
    list[ctr++] = createProduct(3, "Marmalade", 18, createDate(25, 8, 2023), 30);
    list[ctr++] = createProduct(4, "Chocolate Chaud", 24, createDate(25, 11, 2024), 25);
    list[ctr++] = createProduct(5, "Compote", 18, createDate(7, 3, 2023), 5);
    list[ctr++] = createProduct(6, "Spiced Sea Salt", 36, createDate(1, 0, 2024), 32);
    list[ctr++] = createProduct(7, "Pizza Paste", 18, createDate(15, 4, 2023), 12);
    list[ctr++] = createProduct(8, "Bruschetta", 18, createDate(21, 7, 2024), 18);
    list[ctr++] = createProduct(9, "Vinaigrette", 18, createDate(14, 5, 2024), 3);
    list[ctr++] = createProduct(10, "Infused Oil", 18, createDate(25, 8, 2023), 30);
    list[ctr++] = createProduct(11, "Butter", 4, createDate(18, 9, 2023), 10);
    list[ctr++] = createProduct(12, "Beans", 12, createDate(14, 1, 2024), 17);
    list[ctr++] = createProduct(13, "Olives", 24, createDate(29, 7, 2023), 30);
    list[ctr++] = createProduct(14, "Pickles", 24, createDate(21, 11, 2024), 25);
    list[ctr++] = createProduct(15, "Cereal", 12, createDate(4, 3, 2024), 5);
    list[ctr++] = createProduct(16, "Yogurt", 4, createDate(1, 0, 2025), 32);
    list[ctr++] = createProduct(17, "Pork", 1, createDate(20, 4, 2025), 12);
    list[ctr++] = createProduct(18, "Cream", 2, createDate(29, 4, 2025), 18);
    list[ctr++] = createProduct(19, "Cheese", 12, createDate(8, 1, 2024), 3);
    list[ctr++] = createProduct(20, "Milk", 4, createDate(5, 8, 2023), 30);

    if(option == 1) {
        memcpy(prods.prods, list, sizeof(Product) * count);
        prods.count = count;
    } else if(option == 2) {
        memcpy(prods.prods, list+10, sizeof(Product) * count);
        prods.count = count;
    } else if(option == 3) {
        for(int i = 0; i < 20 && count > prods.count; ++i) {
            if(i % 2 == 0) {
                prods.prods[prods.count++] = list[i];
            }
        }
    } else {
        for(int i = 0; i < 20 && count > prods.count; ++i) {
            if(i % 2 == 1) {
                prods.prods[prods.count++] = list[i];
            }
        }
    }

    return prods;
}