#include<float.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
int main() {
   // printf() displays the string inside quotation
   int a = INT_MAX;
   float b = FLT_MAX;
   double c=DBL_MAX;   
   printf("%d \n",a);
   printf("%f \n",b);
   printf("%f \n",c);

   printf("Integer size: %ld \n",sizeof(a));
   printf("Float size: %ld \n",sizeof(b));
   printf("Double size: %ld \n",sizeof(c));
   return 0;
}
