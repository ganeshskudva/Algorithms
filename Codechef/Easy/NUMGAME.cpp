#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

int main()
{
	ull t, n;

	cin >> t;
	while(t--)
	{
		cin >> n;

		printf("%s\n",(n%2)?"BOB":"ALICE" );
	}

	return 0;
}