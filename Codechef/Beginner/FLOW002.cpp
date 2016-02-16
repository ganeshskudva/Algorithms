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

int main()
{
	ll t,a, b;

	t = readInt();

	while (t--)
	{
		a = readInt();
		b = readInt();
		printf("%lld\n",a%b);
	}

	return 0;
}
