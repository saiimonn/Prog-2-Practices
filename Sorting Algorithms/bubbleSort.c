#include <stdio.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
}

void bubbleSort(int arr[], int size) {
    int i, j;
    int swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        printf("[%d] - ", i);
        scanf("%d", &arr[i]);
    }

    printf("Original, unsorted array: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("\nSorted array: ");
    printArray(arr, size);
}