#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

#define GETCHAR getchar_unlocked
inline ll readInt() 
{
    ll n = 0;
    char c;
    while (1)
    { 
		c=GETCHAR();
		if(c=='\n'||c==' ') break;
		n = n * 10 + c - '0';
    }
    return n;
}

ll get_sum(ll n)
{
	ll sum = 0;

	while (n)
	{
		if ((n%10) == 4)
		{
			sum++;
		}
		n /= 10;
	}

	return sum;
}

int main()
{
	ll t,n;

	t = readInt();

	while (t--)
	{
		n = readInt();
		printf("%lld\n",get_sum(n));
	}

	return 0;
}
