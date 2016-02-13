#include <bits/stdc++.h>

using namespace std;

unsigned long long fact(unsigned long long n)
{
	unsigned long long count = 0;
	int i = 0;
	int div = 5;

	for (i = 1; n/pow(div, i); i++)
	{
		count += (n/pow(div, i));
	}

	return count;
}

int main()
{
	unsigned long long t, n;

	cin >> t;
	while (t--)
	{	
		cin >> n;
		cout << fact(n) << endl;
	}

	return 0;
}