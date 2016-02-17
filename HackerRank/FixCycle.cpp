#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define GETCHAR getchar_unlocked
inline int readInt() 
{
    int n = 0;
    int sign = 1;
    char c;
    while (1)
    { 
		c=GETCHAR();
		if(c=='\n'||c==' ') break;
		if(c == '-')
		{
			sign = -1;
			continue;
		}
		n = n * 10 + c - '0';
		n *= sign;
		sign = 1;
    }
    return n;
}

int main() {
    
    int a,b,c,d,e,f;
    int Pabcd=0,Pabd=0,Pabc=0;
    int Sabcd=0, Sabd=0, Sabc=0;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    scanf("%d",&f);

    if ((a > 0) && (b > 0) && (c > 0) && (d > 0) && (e > 0) && (f > 0))
    {
    	printf("0\n");
    	return 0;
    }

    Sabcd = a+b+c+d;
    Sabc = a+b+c;
    Sabd = a+b+d;

    if ((Sabcd + Sabc + Sabd ) <  -20)
    {
        printf("-1\n");
        return 0;
    }

    if (Sabcd < 0)
    {
    	Pabcd = -1 * Sabcd;
    }

    if (Sabd < 0)
    {
    	Pabd = -1 * Sabd;
    }

    if (Sabc < 0)
    {
    	Pabc = -1 *Sabc;
    }

    if (Pabcd <= Pabd)
    {
    	if (Pabcd <= Pabc)
    	{
    		printf("%d\n", Pabcd);
    	}
    }
    else if (Pabd <= Pabc)
    {
    	printf("%d\n", Pabd);
    }
    else
    {
    	printf("%d\n", Pabc);
    }


    return 0;
}
