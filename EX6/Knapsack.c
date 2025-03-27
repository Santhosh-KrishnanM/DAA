#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
        return (a > b) ? a : b;
}
void knapsack(int W, int weight[], int value[], int n)
{

        int K[n + 1][W + 1];
        int i,j,w;
        for (i = 0; i <= n; i++)
        {
                for (w = 0; w <= W; w++)
                {
                        if (i == 0 || w == 0)
                        {
                                K[i][w] = 0;
                        }
                        else if (weight[i - 1] <= w)
                        {
                                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
                        }
                        else
                        {
                                K[i][w] = K[i - 1][w];
                        }
                        printf("%d\t",K[i][w]);
                }
                printf("\n");
        }
        int res = K[n][W];
        printf("Maximum value in Knapsack = %d\n", res);
        w = W;
        printf("Items included in the knapsack:\n");
        for (i = n; i > 0 && res > 0; i--)
        {
                if (res == K[i - 1][w])
                        continue;
                else
                {
                        printf("Item %d (Value: %d, Weight: %d)\n", i, value[i - 1], weight[i - 1]);
                        res = res - value[i - 1];
                        w = w - weight[i - 1];
                }
        }
}
int main()
{
        int n, W, i;
        int *value, *weight;
        printf("Enter no of items: ");
        scanf("%d", &n);
        value = (int *)malloc(n * sizeof(int));
        weight = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
                printf("Item %d :: Enter value, weight:", i + 1);
                scanf("%d,%d", &value[i], &weight[i]);
        }
        printf("Enter capacity of the knapsack:");
        scanf("%d", &W);
        knapsack(W, weight, value, n);
        return 0;
}