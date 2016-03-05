#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

int main()
{
	int t,i;
	int found = 0;
	cin >> t;
	std::string a, b;

	while(t--)
	{
		cin >> a;
		cin >> b;

		for (i = 0; i < a.size(); i++)
		{
			if (b.find(a[i]) != std::string::npos)
			{
				cout << "Yes" << endl;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			cout << "No" << endl;
		}
		found = 0;
	}	

	return 0;
}