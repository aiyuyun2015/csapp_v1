#include <stdio.h>
int main( void )
{
int i;

for (;;)
   {
      fputs("Please input an integer: ", stdout);
      scanf("%d", &i);
      printf("%d\n", i);
}

   return 0;
}