#include<stdio.h>
int power(int a, int n){
   int s = 1;
   int i;
   for (i = 0; i < n; i++){
      s *= a;
   }
   return s;
}
int main(){
   int a, n;
   printf("Enter the base and power\n");
   printf("----------------------------\n");
   printf("Base: ");
   scanf("%d", &a);

   /*printf("Power: ");
   scanf("%d", &n);*/
   while (1){
      printf("Power: ");
      scanf("%d", &n);
      if(n>=0){
         break;
      }else{
         printf("Power should not be negative\n");
         printf("Enter valid power value\n");
         //scanf("%d", &n);
         printf("----------------------------\n");
      }
   }

   /*if(n < 0){
      printf("-------------------------------\n");
      printf("Power should not be negative\n");
      printf("Enter valid power value: ");
      scanf("%d", &n);
      printf("-------------------------------");
      int powerres = power(a,n);
      printf(" \n%d to the power %d is %d\n", a, n, powerres);
      printf("-------------------------------\n");
   }*/
   int powerres = power(a,n);
   printf("-------------------------------");
   printf(" \n%d to the power %d is %d\n", a, n, powerres);
   printf("-------------------------------\n");

   return 0;
}
