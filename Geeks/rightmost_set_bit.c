/*
 * This algorithm returns the position of rightmost set bit in a given number
 */

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

int set_bit(int n)
{
    if (n) {
        return (log (n&(-n)) / log (2) + 1);
    }

    return 0;
}

int main ()
{
    int i = 0;
    int num = 0;
    srand(time(NULL));
 
    for (i = 0; i<10; i++) {  
         num = rand()%10;
         printf("\nNum:%d Set bit:%d\n",num, set_bit(num));
    }
    
    return 0;
}
