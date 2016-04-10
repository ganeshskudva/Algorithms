#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

typedef unsigned long long int ull;

using namespace std;

#define DEBUG 0

bool is_power_of_two(ull x)
{
	return x && (!(x&(x-1)));
}

ull largest_power_of_two(ull x)
{
	return pow(2,floor(log(x)/log(2)));
}

int main()
{
	ull t = 0, n, cnt = 0;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 



	while (t--)
	{
		cnt = 0;
#if DEBUG
		n = (rand()%100)+1;
		cout << n << endl;
#else
		cin >> n;
#endif

		if (n == 1)
		{
			cnt++;
			continue;
		}

		while (n != 1)
		{
			if (is_power_of_two(n))
			{
				n = n/2;
			}
			else
			{
				n = n - largest_power_of_two(n);
			}

			cnt++;
		}
		printf("%s\n", (cnt % 2)?"Louise":"Richard");
	}


	return 0;
}