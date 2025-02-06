#include<stdio.h>
#include<math.h>
#include<float.h>

struct Coordinate{
   float x;
   float y;
};


float FindClosest(int n,struct Coordinate pt[],struct Coordinate closest[])
{
   int i,j;
   float min = INFINITY ,distance;
   for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
      {
         distance = sqrt(pow(pt[i].x-pt[j].x,2)+pow(pt[i].y-pt[j].y,2));
         if(distance<min)
         {
            min=distance;
            closest[0]=pt[i];
            closest[1]=pt[j];
         }
      }
   }
   return min;
}

int main(){
   int i,n;
   float dis;

   printf("Enter no. of points: ");
   scanf("%d", &n);

   struct Coordinate c1[n];
   struct Coordinate clo[2];

   printf("Enter the coordinates(x,y)\n");
   for(i=0;i<n;i++){
      printf("x%i: ", i);
      scanf("%f", &c1[i].x);
      printf("y%i: ", i);
      scanf("%f", &c1[i].y);
      dis = FindClosest(n,c1,clo);
   }

   printf("The minimum distance: %.2f\n", dis);
   printf("The closest pair is [%.2f,%.2f] and [%.2f,%.2f]\n", clo[0].x,clo[0].y,clo[1].x,clo[1].y);
   return 0;
}
