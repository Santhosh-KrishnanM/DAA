#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b, int *arr, int low, int high) {
    // Print before swap
    int i;
    printf("Before swap: ");
    for (i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int temp = *a;
    *a = *b;
    *b = temp;

    // Print after swap
    printf("After swap: ");
    for (i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i,j;

    printf("Pivot selected: %d\n", pivot);
    printf("Current sub-array: ");
    for (i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j], arr, low, high);
        }
    }
    swap(&arr[i + 1], &arr[high], arr, low, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
