#include <bits/stdc++.h>

using namespace std;

unsigned long long fact(unsigned long long val)
{
	unsigned long long count = 1;

	while (val)
	{
		count *= val;
		val--;
	}

	return count;
}

int main ()
{
	unsigned long long n, val;
#if 0
	cin >> n;

	while (n--)
	{
		cin >> val;
		cout << fact(val) << endl;
	}
#endif

	n = val = 100;
	while (n--)
	{
		cout<< "Fact of "<<val<<":"<<fact(val) << endl;
		val--;
	}
	return 0;
}