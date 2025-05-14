//CODE HERE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mylib.h"
#include "mydate.h"

bool addItemSortedByMFG(ProductList *list, Product p) {
    if (list->count == list->max) {
        return false;
    }

    int i = 0;
    while (i < list->count && 
          (list->prods[i].prodMFG.year > p.prodMFG.year || 
          (list->prods[i].prodMFG.year == p.prodMFG.year && list->prods[i].prodMFG.month > p.prodMFG.month) || 
          (list->prods[i].prodMFG.year == p.prodMFG.year && list->prods[i].prodMFG.month == p.prodMFG.month && list->prods[i].prodMFG.date > p.prodMFG.date))) {
        i++;
    }

    for (int j = list->count; j > i; j--) {
        list->prods[j] = list->prods[j - 1];
    }

    list->prods[i] = p;
    list->count++; 
    return true;
}


int main() {
    ProductList productList, sortedProductList;
    int option;
    int count;

    printf("Enter option: ");
    scanf("%d", &option);
    printf("Enter count: ");
    scanf("%d", &count);

    productList = populateProductList(option, count);

    sortedProductList.prods = (Product*) malloc(sizeof(Product) * productList.max);
    sortedProductList.count = 0; 
    sortedProductList.max = productList.max;

    for (int i = 0; i < productList.count; i++) {
        addItemSortedByMFG(&sortedProductList, productList.prods[i]);
    }

    printf("\nOriginal List:\n");
    displayProducts(productList);

    printf("\nSorted List (MFG):\n");
    displayProducts(sortedProductList);

    free(sortedProductList.prods);

    return 0;
}