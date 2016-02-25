#include <bits/stdc++.h>

typedef unsigned long long int ull;
#define MAX 10000
#define MIN 100000

using namespace std;

int main()
{
	ull arr[MAX+1], t, n, min = MIN, count = 0;

	

	cin >> t;
	while (t--)
	{
		memset(arr, 0, (MAX+1) * sizeof(ull));
		cin >> n;
		ull in[n];
		int i = 0;
		while(n--)
		{
			cin >> in[i];
			arr[in[i]]++;
			i++;
		}
		min = MIN;
		for (i = 1; i <= MAX; i++)
		{
			if (arr[i] && (arr[i] > count))
			{
				count = arr[i];
				min = i;

			}
		}
		cout << min<<" "<<count <<endl;
		count = 0;
	}
	return 0;
}