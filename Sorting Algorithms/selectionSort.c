#include <stdio.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int min = i;

        for(int j = i; j < size; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        printf("[%d] - ", i);
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("\nSorted array: ");
    printArray(arr, size);
}