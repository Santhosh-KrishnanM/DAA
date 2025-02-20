#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *arr;
    int min, max;

    // Prompt user for array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read array elements from user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize min and max with the first element
    if (size == 0) {
        printf("Array is empty.\n");
        free(arr);
        return 0;
    }
    min = max = arr[0];

    // Find min and max
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Output the results
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    // Free the allocated memory
    free(arr);
    return 0;
}
