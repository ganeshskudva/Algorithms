#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main()
{
	ll t, N;

	cin >> t;
	while (t--)
	{
		cin >> N;
		if (N%2)
		{
			cout << (N-1) << endl;
		}
		else
		{
			cout << N << endl;
		}
	}
	return 0;
}