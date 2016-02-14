#include <bits/stdc++.h>

using namespace std;

#define MAX_MENU 12
typedef unsigned long long int ull;

int main ()
{
	int t,i;
	int price[MAX_MENU];
	ull max_dish = 0;
	ull p;

	for (i =0; i < MAX_MENU; i++)
	{
		price[i] = pow(2, i);
 	}

 	cin >> t;
 	while (t--)
 	{
 		cin >> p;

 		for (i = (MAX_MENU-1); i >=0; i--)
 		{
 			if (p >= price[i])
 			{
 				max_dish += (p / price[i]);
 				p %= price[i];
 			}
 		}

 		cout << max_dish << endl;
 		max_dish = 0;
 	}

 	return 0;
}