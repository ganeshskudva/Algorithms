#include <bits/stdc++.h>

typedef long long int ull;

using namespace std;

int main()
{
	ull t,n,k, i;

	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		if (n == 1 && k == 1)
		{
			cout << 1 << endl;
		}
		else if(k > n/2)
		{
			cout << -1 << endl;
		}
		else
		{
			for (i = 1; i <=k; i++)
			{
				cout<<2*i<<" ";
			}
		}

		cout<< endl;

	}
	return 0;
}
