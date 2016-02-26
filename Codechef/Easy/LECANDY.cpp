#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

int main()
{	
	ull t, n, c;

	cin >> t;

	while (t--)
	{
		cin >> n;
		cin >> c;
		ull arr[n];
		ull sum = 0, i;
		memset(arr, 0, n*sizeof(ull));

		for (i = 0; i < n; i++)
		{
		   	cin >> arr[i];
 			sum += arr[i];
		}
		if(sum <= c)
		{
			cout << "Yes"<<endl;
		}
		else
		{
			cout << "No"<<endl;
		}
		sum = 0;
	}
	return 0;
}
