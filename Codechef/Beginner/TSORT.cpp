#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main ()
{

	ull n, val;
	std::vector<ull> vect;
	cin >> n;

	while (n--)
	{
		cin >> val;
		vect.push_back(val);
	}

	std::sort(vect.begin(), vect.end());
	for (std::vector<ull>::iterator it = vect.begin(); it != vect.end();it++)
	{	
		cout << *it << endl;
	}
	return 0;
}