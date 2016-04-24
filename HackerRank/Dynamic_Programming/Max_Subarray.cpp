#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long int ull;

#define MEM(a, b, c, d) memset(a, (b), c * sizeof(d))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

#if 0
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
#endif

#define IN(A, B, C) assert( B <= A && A <= C)

using namespace std;

#define DEBUG 0

int main()
{
	ull t = 0, n, i, sum, tot_sum, non_cont_sum;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> n;
		sum = 0;
		tot_sum = 0;
		non_cont_sum = 0;
		ull arr[n];
		MEM(arr, 0, n, ull);

		cin >> arr[0];
		sum = arr[0];
		tot_sum = arr[0];
		non_cont_sum = arr[0];
		for (i = 1; i < n; i++)
		{
			cin >> arr[i];
			tot_sum += arr[i];

			if (arr[i] > 0)
			{
				non_cont_sum += arr[i];
			}

			if (sum <= tot_sum)
			{
				sum = tot_sum;
			}
			else if (sum < arr[i])
			{
				sum = arr[i];
			}
		}
		cout <<sum<<" "<<non_cont_sum<<endl;

	}

	return 0;
}
