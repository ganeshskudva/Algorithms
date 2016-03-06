#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

int main()
{
	int t;
	cin >> t;
	std::string str1, str2;
	ull len, i, count = 0;
	std::size_t found = 0;


	while(t--)
	{
		count = 0;
		cin >> str1;
		cin >> str2;

		for (i = 0; i < str2.length(); i++)
		{
			found = str1.find(str2[i]);
			if (found != std::string::npos)
			{
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}
