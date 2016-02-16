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
	ll t, A, B;

	t = readInt();

	while (t--)
	{
		A = readInt();
		B = readInt();

		printf("%lld\n",A+B);
	}

	return 0;
}
