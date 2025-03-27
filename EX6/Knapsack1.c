#include <stdio.h>
#include <stdlib.h>

int MFKnapsack(int** F, int* w, int* v, int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (F[i][j]>= 0) {
        return F[i][j];
    }
    if (w[i-1]>j) {
        F[i][j] = MFKnapsack(F, w, v, i-1, j);
        printf("F[%d][%d]= %d\n",i,j,F[i][j]);
    } else {
        int v1 = MFKnapsack(F, w, v, i-1, j);
        int v2 = v[i-1] + MFKnapsack(F, w, v, i-1, j-w[i-1]);
        F[i][j] = (v1 > v2) ? v1 : v2;
        printf("F[%d][%d]= %d\n",i,j,F[i][j]);
    }
    return F[i][j];
}
int main() {
    int n, cap;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &cap);
    int i,j;
    int** F = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
        F[i] = (int*)malloc((cap + 1) * sizeof(int));
    }
    int w[n];
    int v[n];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= cap; j++) {
            F[i][j] = -1;
        }
    }
    for (i = 1; i <= n; i++) {
        printf("Item %d:\n", i);
        printf("Weight: ");
        scanf("%d", &w[i-1]);
        printf("Value: ");
        scanf("%d", &v[i-1]);
    }
    int optValue = MFKnapsack(F, w, v, n, cap);
    printf("Optimal Knapsack value: %d\n", optValue);
    printf("Knapsack Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            printf("%d\t", F[i][j]);
        }
        printf("\n");
    }
    i=n;
    j=cap;
    while (i > 0 && j > 0) {
        if (F[i][j] > F[i-1][j]) {
            printf("F[%d][%d] is greater than F[%d][%d], so item %d is chosen\n", i,j,i,j-1,i);
            j -= w[i-1];
            printf("Current capacity of the knapsack: %d\n",j);
        }
        i--;
    }
    return 0;
}