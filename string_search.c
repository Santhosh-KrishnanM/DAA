#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int match_Pattern(char *string, char *key){
   int i,j,k;
   int n = strlen(string)-1;
   int m = strlen(key)-1;
   printf("%s",string);
   for(i = 0; i<n-m+1; i++){
      k = 0;
      for(j = 0;j < i; j++){
         printf(" ");
      }

      printf("%s",key);

      while(k<m && string[i+k] == key[k])
         k++;
      if(k==m)
         return 1;
   }
   return -1;
}

int main(){
   char *string1;
   char *text;
   string1 = (char*)malloc(100*sizeof(char));
   text = (char*)malloc(100*sizeof(char));
   printf("\tString searching using Brute Force Technique\n");

   printf("Enter the string: ");
   fgets(string1, 100, stdin);

   printf("Enter the text to search: ");
   fgets(text, 100, stdin);

   int r = match_Pattern(string1,text);

   if(r>0)
      printf("String matched\n");
   else
      printf("String not matched\n");
   return 0;

}
