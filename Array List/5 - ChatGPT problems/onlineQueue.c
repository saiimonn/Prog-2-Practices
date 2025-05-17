#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100
#define MAX_ITEM 50

typedef struct {
    int orderID;
    char item[MAX_ITEM];
} Order;

typedef struct {
    Order orders[MAX_ORDERS];
    int count;
} OrderQueue;

// Function declarations
void initQueue(OrderQueue *q) {
    q->count = 0;
}

void enqueue(OrderQueue *q, Order o) {
    if(q->count >= MAX_ORDERS) {
        printf("Queue is full\n");
        return;
    }

    for(int i = q->count; i > 0; i--) {
        q->orders[i] = q->orders[i - 1];
    }
    q->orders[0] = o;
    q->count++;
}

Order dequeue(OrderQueue *q) {
    
}

void displayQueue(OrderQueue q) {

}

int main() {
    OrderQueue queue;
    initQueue(&queue);

    enqueue(&queue, (Order){1, "Laptop"});
    enqueue(&queue, (Order){2, "Mouse"});
    displayQueue(queue);

    Order processed = dequeue(&queue);
    printf("Processed Order ID: %d (%s)\n", processed.orderID, processed.item);

    displayQueue(queue);
    return 0;
}