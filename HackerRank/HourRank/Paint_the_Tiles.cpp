#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ull;

using namespace std;

#define DEBUG 0

int main()
{
	ull t = 0, i, cnt = 1;
	std::string color_str;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<N<<endl;
#else 
	cin >> t;
#endif 

//	while (t--)
//	{
		cin >> color_str;
		for (i = 1; i < color_str.length(); i++)
		{
			if (color_str[i] != color_str[i-1])
			{
				cnt++;
			}
		}
		cout << cnt;
		cnt = 0;
//	}

	return 0;
}
