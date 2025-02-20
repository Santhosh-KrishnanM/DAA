#include <stdio.h>
#include <stdlib.h>

void dispass(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int n) {
    int i, j, min, temp;
    printf("-------------------------------\n");
    for (i = 0; i < n - 1; i++) {
        printf("Pass %d: \n", i+1);
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
        dispass(a, n);
    }
    printf("-------------------------------\n");
}

int main() {
    int i, n;
    printf("\tSelection Sort");
    printf("\n\nNumber of the input data: ");
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("-------------------------------\n  List: ");
    dispass(a,n);
    printf("-------------------------------\n");
    selectionSort(a, n);
    free(a);
    return 0;
}
