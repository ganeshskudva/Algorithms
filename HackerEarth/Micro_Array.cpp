/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/micro-and-array-1/
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
#define DUMMY_MAX -2000000

ull get_idx (ull arr[], ull n, ull val)
{
	ull i, idx = -1;

	FORN(i , n)
	{
		if (arr[i] >= val)
		{
			idx = i + 1;
			break;
		}
	}

	return idx;
}

int main()
{
	ull n = 0,i,j, type, q, max, maxidx;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> q;
#endif 

	ull arr[n];
	MEM(arr, 0, n, ull);

	FORN(i, n)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
			maxidx = i;
		}
	}

	while (q--)
	{
		cin >> type;;

		switch(type)
		{
			case 0: cin >> i >> j;
					if (j > max)
					{
						max = j;
						maxidx = i - 1;
					}
					arr[i - 1] = j;
					break;
			case 1: cin >> i;
					if (i == max)
					{
						cout << maxidx + 1<<endl;
					}
					else if (i < max)
					{
						cout << get_idx(arr, n, i) << endl;

					}
					else
					{

						cout << -1 << endl;
					}
					break;
			default: break;

		}
	}


	return 0;
}
