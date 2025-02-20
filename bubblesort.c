#include <stdio.h>
#include <stdlib.h>

void dispass(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[], int n) {
    int i, j, temp;
    printf("-------------------------------------------------------\n");
    for (i = 0; i < n - 1; i++) {
       printf("Pass %d: \n", i+1);
        for (j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            //printf("Pass %d: ", i + 1);
            dispass(a, n);
            printf("\n");
        }
        printf("-------------------------------------------------------\n");
    }
}

int main() {
    int i, n;
    int *a;

    printf("\tBubble sort\n");
    printf("\nEnter the number of inputs: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("-------------------------------------------------------\n");
    printf("  List before bubble sort:  ");
    dispass(a, n);

    bubbleSort(a, n);

    printf("  List after bubble sort:  ");
    dispass(a, n);
    printf("--------------------------------------------------------\n");
    free(a);
    return 0;
}
