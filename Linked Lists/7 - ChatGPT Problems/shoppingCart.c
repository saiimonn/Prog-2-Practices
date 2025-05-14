#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char product[50];
    int quantity;
    float price;
} CartItem;

typedef struct node {
    CartItem data;
    struct node *next;
} CartNode;

void addItem(CartNode **head, CartItem item) {
    CartNode *newNode = malloc(sizeof(CartNode));
    newNode->data = item;
    newNode->next = *head;
    *head = newNode;
}

void removeItem(CartNode **head, const char *product) {
    if(*head == NULL) {
        printf("Empty list\n");
        return;
    }

    CartNode *temp;
    if(strcmp((*head)->data.product, product) == 0) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    CartNode *prev;
    for(temp = *head, prev = NULL; temp != NULL && strcmp(temp->data.product, product) != 0; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Product no exist\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void updateQuantity(CartNode *head, const char *product, int newQty) {
    if(head == NULL) {
        printf("Empty list\n");
        return;
    }

    CartNode *ptr;
    for(ptr = head; ptr != NULL && strcmp(ptr->data.product, product) != 0; ptr = ptr->next) {}

    if(ptr == NULL) {
        printf("Product not found\n");
        return;
    }

    ptr->data.quantity = newQty;
}

void displayCart(CartNode *head) {
    if(head == NULL) {
        printf("Empty\n");
        return;
    }

    CartNode *ptr;
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("{%s, %d, %.2f} -> ", ptr->data.product, ptr->data.quantity, ptr->data.price);
    printf("NULL\n");
}

int main() {
    CartNode *cart = NULL;

    CartItem i1 = {"Laptop", 1, 1200.00};
    CartItem i2 = {"Mouse", 2, 25.50};
    CartItem i3 = {"Keyboard", 1, 45.00};

    addItem(&cart, i1);
    addItem(&cart, i2);
    addItem(&cart, i3);

    displayCart(cart);

    updateQuantity(cart, "Mouse", 3);
    removeItem(&cart, "Keyboard");

    printf("\nAfter updates:\n");
    displayCart(cart);

    return 0;
}