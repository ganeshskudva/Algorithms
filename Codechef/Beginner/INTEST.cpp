#include <bits/stdc++.h>

using namespace std;
int main ()
{
	unsigned long long n , k, val;
	unsigned long long count = 0;
	cin >> n >> k;

	while (n--)
	{
		cin >> val;
		if ((val % k) == 0)
		{
			count++;
		}
	}

	cout<<count<<endl;

	return 0;

}