#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the no. of elements: ");
    int n;
    scanf("%d",&n);
    printf("\n");
    int* arr = (int*)malloc(sizeof(int)*n);
    int* res = (int*)malloc(sizeof(int)*n);
    int* count = (int*)malloc(sizeof(int)*n);
    int i,j;
    for(i=0;i<n;i++){
        count[i]=0;
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nCount array:\n");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]<=arr[j])
            count[j]++;
            else
            count[i]++;
        }
        for(j=0;j<n;j++){
            printf("%d ",count[j]);
        }
        printf("\n");
    }
    printf("\nSorted array:\n");
    for(i=0;i<n;i++){
        res[count[i]]= arr[i];
    }
    for(i=0;i<n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}