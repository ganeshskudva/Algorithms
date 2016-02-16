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

ll reverse(ll n)
{
	ll rev = 0;

	while (n)
	{
		rev = (rev * 10) + (n % 10);
		n /= 10;
	}

	return rev;
}

int main()
{
	ll t,a;

	t = readInt();

	while (t--)
	{
		a = readInt();
		printf("%lld\n",reverse(a));
	}

	return 0;
}
