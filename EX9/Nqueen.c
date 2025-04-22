#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display(int* sol, int n) {
    int i, j;
    printf("Board\n");
    for (i = 0; i < n * 4; i++)
        printf("-");
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("|");
            if (sol[i] == j)
                printf(" Q ");
            else
                printf("   ");
        }
        printf("|\n ");
        for (j = 0; j < n*4; j++) {
            printf("-");
        }
        printf("\n");
    }
}

bool checkQueen(int k, int l, int* sol, int n) {
    int i;
    for (i = 0; i < k; i++) {
        if (sol[i] == l || abs(sol[i] - l) == abs(i - k))
            return false;
    }
    return true;
}

bool placeQueen(int col, int* sol, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (checkQueen(col, i, sol, n)) {
            sol[col] = i;
            if (placeQueen(col + 1, sol, n))
                return true;
            sol[col] = -1; // Backtrack
        }
    }
    return false;
}

int main() {
    int n, i;
    printf("Enter board size: ");
    scanf("%d", &n);

    int* sol = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        sol[i] = -1;

    if (placeQueen(0, sol, n)) {
        printf("\nSolution: ");
        for (i = 0; i < n; i++)
            printf("%d ", sol[i]+1);
        printf("\n");
        display(sol, n);
    } else {
        printf("No solution exists for the given board size.\n");
    }

    free(sol);
    return 0;
}