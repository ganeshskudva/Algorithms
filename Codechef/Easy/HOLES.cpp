#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

map <const char , int> mymap;

int main()
{
	int i = 0;
	int t = 0;
	int sum = 0;
	std::string str;

	mymap['A']=1;
mymap['B']=2;
mymap['C']=0;
mymap['D']=1;
mymap['E']=0;
mymap['F']=0;
mymap['G']=0;
mymap['H']=0;
mymap['I']=0;
mymap['J']=0;
mymap['K']=0;
mymap['L']=0;
mymap['M']=0;
mymap['N']=0;
mymap['O']=1;
mymap['P']=1;
mymap['Q']=1;
mymap['R']=1;
mymap['S']=0;
mymap['T']=0;
mymap['U']=0;
mymap['V']=0;
mymap['W']=0;
mymap['X']=0;
mymap['Y']=0;
mymap['Z']=0;

	cin >> t;
	while (t--)
	{
		cin>>str;
		for (i = 0; i < str.length(); i++)
		{
			sum += mymap[str.at(i)];
		}

		cout << sum;
		sum = 0;
	}

	return 0;
}


