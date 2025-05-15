#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct Product {
    int product_id;
    char product[50];
    float price;
    struct Product *next;
} Product;

// Function prototypes
void addProduct(Product **head);
void updatePrice(Product *head);
void removeProduct(Product **head);
void displayProducts(Product *head);
void freeList(Product *head);

int main() {
    Product *head = NULL;
    int choice;

    do {
        printf("\nProduct Management System\n");
        printf("1. Add a Product\n");
        printf("2. Update Product Price\n");
        printf("3. Remove a Product\n");
        printf("4. Display All Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addProduct(&head);
                break;
            case 2:
                updatePrice(head);
                break;
            case 3:
                removeProduct(&head);
                break;
            case 4:
                displayProducts(head);
                break;
            case 5:
                printf("Exiting program...\n");
                freeList(head);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new product to the end of the list
void addProduct(Product **head) {
    // ADD CODE HERE...
    Product *newProduct = malloc(sizeof(Product));
    if(newProduct == NULL) {
        printf("Memoray allocation failed\n");
        exit(0);
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &newProduct->product_id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]s", newProduct->product);

    printf("Enter Product Price: ");
    scanf("%f", &newProduct->price);

    newProduct->next = NULL;

    if(*head == NULL) {
        *head = newProduct;
        printf("Product added successfully!\n");
        return;
    }

    Product *ptr;
    for(ptr = *head; ptr->next != NULL; ptr = ptr->next) {}

    ptr->next = newProduct;
}

// Function to update a product's price
void updatePrice(Product *head) {
    // ADD CODE HERE...
    int id;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    if(head == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    float newPrice;
    printf("Enter new price: ");
    scanf("%f", &newPrice);

    Product *trav;
    for(trav = head; trav != NULL && trav->product_id != id; trav = trav->next) {}

    if(trav == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    trav->price = newPrice;
}

// Function to remove a product by product_id
void removeProduct(Product **head) {
    // ADD CODE HERE...
    int id;
    printf("\nEnter Product ID to remove: ");
    scanf("%d", &id);

    if(*head == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    Product *temp;
    if((*head)->product_id == id) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Product removed successfully\n");
        return;
    }

    Product *prev;
    for(temp = *head, prev = NULL; temp != NULL && temp->product_id != id; prev = temp, temp = temp->next) {}

    if(temp == NULL) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display all products
void displayProducts(Product *head) {
    // ADD CODE HERE...
    if(head == NULL) {
        printf("No products to display.\n");
        return;
    }

    Product *ptr;
    printf("\nProducts List:\n");
    printf("ID\tName\t\tPrice\t\n");
    printf("---------------------------------\n");
    
    for(ptr = head; ptr != NULL; ptr = ptr->next) printf("%d\t%-15s\t%.2f\n", ptr->product_id, ptr->product, ptr->price);
}

// Function to free the entire list before exiting
void freeList(Product *head) {
    // ADD CODE HERE...
    Product *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}