/*
* AUTHOR: Ganesh S Kudva
*/

#include <bits/stdc++.h>

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
#define CLOCK 0
#define DUMMY_MAX -(2 * 100000000)

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, n , k, max, max_prev;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> k;
#endif 

	ull arr[n];
	MEM(arr, 0, n, ull);
	max = DUMMY_MAX;

	FORN(i, n)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	if ((k % 2) == 1)
	{
		k = 1;
	}
	else
	{
		if (k > 2)
		{
			k = 2;
		}

	}

	while (k--)
	{
		max_prev = max;
		max = DUMMY_MAX;
		FORN(i, n)
		{
			arr[i] = max_prev - arr[i];

			if (arr[i] > max)
			{
				max = arr[i];
			}
		}

	}

	FORN(i, n)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
