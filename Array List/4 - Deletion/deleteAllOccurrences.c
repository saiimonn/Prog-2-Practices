    #include <stdio.h>
    #include <stdlib.h>

    #define MAX 100

    typedef struct {
        int data[MAX];
        int size;
    } List;

    void initializeList(List *list) {
        list->size = 0;
    }

    void insertSorted(List *list, int val) {
        if(list->size >= MAX) return;

        int idx;
        for(idx = 0; idx < list->size && list->data[idx] <= val; idx++) {}

        for(int i = list->size; i > idx; i--) list->data[i] = list->data[i - 1];

        list->data[idx] = val;
        list->size++;
    }

    void deleteAllOccurrences(List *list, int x) {
        if(list->size == 0) return;

        int idx = 0;
        for(int i = 0; i < list->size; i++) {
            if(list->data[i] != x ) {
                list->data[idx++] = list->data[i];
            }
        }
        list->size = idx;
    }

    void display(List *list) {

    }

    int main() {
        List myList;
        initializeList(&myList);
    }