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
#define DUMMY_MAX -100000

int main()
{
	ull t = 0,i,j, cnt, max_till_now, n;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n;
#endif 

	ull arr[n];
	MEM(arr, 0, n, ull);

	cnt = 0;
	max_till_now = DUMMY_MAX;
	FORN(i, n)
	{
		cin >> arr[i];

		if (arr[i])
		{
			cnt++;
		}

		if (!arr[i])
		{
			if (cnt > max_till_now)
			{
				max_till_now = cnt;
			}
			cnt = 0;
		}
	}

	if (cnt > max_till_now)
	{
		cout << cnt << endl;
	}
	else
	{
		cout << max_till_now << endl;
	}
	return 0;
}
