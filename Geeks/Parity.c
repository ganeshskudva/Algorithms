#include "stdio.h"
#include "stdlib.h"

int count(int n)
{
   int cnt = 0;
   
   while (n) {
          n = n & (n - 1);
          cnt++;
   }
   
   return cnt;
}

int main ()
{
    int n = 10;

    printf(" %s Parity", count(n)%2?"Odd": "Even");
    return 0;
}
