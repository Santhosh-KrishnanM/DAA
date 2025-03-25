#include <stdio.h>
#include <stdlib.h>
void printArray(int[] ,int);
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] < arr[smallest])
        smallest = left;
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, size, smallest);
    }
}
void buildMinHeap(int *arr, int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
        printArray(arr,size);
    }
}
int deleteMinHeap(int *arr, int *size) {
    if (*size == 0)
        return -1;
    int minValue = arr[0];
    arr[0] = arr[*size - 1];
    (*size)--;
    heapify(arr, *size, 0);
    return minValue;
}
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    buildMinHeap(arr, n);
    printf("Sorted order: ");
    while (n > 0) {
        printf("%d ", deleteMinHeap(arr, &n));
    }
    printf("\n");
    return 0;
}
