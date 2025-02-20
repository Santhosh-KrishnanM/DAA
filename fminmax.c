#include<stdio.h>
#include<limits.h>
void  dispass(int a[], int n){
   int i;
   for(i = 0; i < n; i++)
      printf("%d", a[i]);
   printf("\n");
}
void findMinMax(int arr[], int low, int high, int* min, int* max){
   if(low == high){
      if(arr[low] < *min)
         min = arr[low];
      if(arr[low] > *max)
         min = arr[low];
   }else if(high == low+1){
      if(arr[low] < arr[high]){
         if(arr[low] < *min)
            min = arr[low];
         if(arr[high] > *max)
            max = arr[high];
      }else{
         if(arr[high] < *min)
            min = arr[high];
         if(arr[low] > *max)
            max = arr[low];
      }
   }
   else{
      int mid = (low+high)/2;
      int rmin,rmax,lmin,lmax;
      findMinMax(arr,mid+1,high,rmax,rmin);
      findMinMax(arr,low,high,lmin,lmax);

   }
}

int main(){
   int i,n;
   printf("Enter number of elements: ");
   scanf("%d", &n);
   int *arr = (int*)malloc(n*sizeof(int));
   printf("Enter the values: ");
   for(i = 0; i < n; i++)
      scanf("%d",&arr[i]);
   printf("\nList: ");
   dispass(arr,n);
   return 0;
}
