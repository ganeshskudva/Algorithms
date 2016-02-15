#include <bits/stdc++.h>

typedef unsigned long long int ll;

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

ll max(ll a, ll b)
{
	return a>b?a:b;
}

int main()
{
	ll t,A,B;

	t = readInt();

	while (t--)
	{
		A = readInt();
		B = readInt();

		cout << max(A,B) <<" "<<A+B<<endl;
	}

	return 0;
}
