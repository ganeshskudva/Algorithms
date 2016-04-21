#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

#define DEBUG 0

int main()
{
	ull t, n, i, tmp;
#if DEBUG
	srand((unsigned)time(0));
	t = (rand()%100)+1;
	cout<<t<<endl;
#else
	cin >> t;
#endif

	while(t--)
	{
		n = 0;
#if DEBUG
		n = (rand()%20)+1;
		cout<<n<<endl;
#else
		cin >> n;
#endif
		ull arr[n];
		memset(arr, 0, n * sizeof(ull));

		for (i = 0; i < n; i++)
		{
#if DEBUG
			arr[i] = (rand()%100)+1;
			cout<<arr[i]<<" ";
#else
			cin >> arr[i];
#endif
		}
		std::sort(arr, arr+n);
		i = 1;
		if ( n > 2)
		{
			do
			{
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				i = i + 2;
			}while ((i+1) < n);
		}
#if DEBUG
			cout<<endl;
#endif
		for (i = 0; i < n; i++)
		{

			cout<< arr[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}