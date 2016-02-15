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
	ll n,r;
	int i = 0;

	n = readInt();

	ll arr[n+1];
	memset(arr, 0, (n + 1) * sizeof(ll));
	for (i = 0; i < n; i++)
	{
		r = readInt();
		arr[r] += 1;
	}

	for (i = 0; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			cout << i <<" ";
		}
	}

	cout<<endl;
	return 0;
}