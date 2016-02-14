#include <bits/stdc++.h>

typedef unsigned long long int ull;
#define MAX 1000

using namespace std;

int main ()
{
	int j,i,n,t = 0;
	int gcd = 0;

	cin >> t;

	 while (t--)
	 {
	 	cin >> n;
	 	int arr[n];

	 	for (i = 0; i < n; i++)
	 	{
	 		cin >> arr[i];
	 	}

	 	for (i = 1; i <= 1000; i++)
	 	{
	 		for (j = 0; j < n; j++)
	 		{
	 			if ((arr[j] % i) != 0)
	 			{
	 				break;
	 			}
	 		}
	 		if (j == n)
	 		{
	 			gcd = i;
	 		}
	 	}

	 	for (i = 0; i < n; i++)
	 	{
	 		cout << arr[i]/gcd << " ";
	 	}

	 	memset(arr, 0, n);

	 }

	return 0;
}
