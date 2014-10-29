/*
 * Program to count the number of set bits in a given number
 */

#include "stdio.h"
#include "stdlib.h"

int count_bit_set(int n)
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

    printf("\nNumber of set bits %d\n",count_bit_set(n));
    return 0;
}
