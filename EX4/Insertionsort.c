#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *arr, int n)
{
    printf("\nPass %d: ", 0);
    int k,i;
    for (k = 0; k < n; k++)
        printf("%d ", arr[k]);
    for (i = 1; i < n; i++)
    {
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
        printf("\nPass %d: ", i);
        for (k = 0; k < n; k++)
        {
        printf("%d ", arr[k]);
        }
    }
}
int main()
{
    int N, i;
    printf("Enter number of elements: ");
    scanf("%d", &N);
    while (N<=0)
    {
        printf("Enter another number of elements: ");
        scanf("%d", &N);
    }
    int *arr = (int *)malloc(N * sizeof(int));
    printf("Enter elements:");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nInsertion Sort");
    insertionSort(arr, N);
    printf("\n\nSorted array:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}