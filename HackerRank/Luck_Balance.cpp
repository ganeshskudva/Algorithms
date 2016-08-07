/*
* AUTHOR: Ganesh S Kudva
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

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
	ull t = 0,i,j, n, k, l, sum, val;
	priority_queue<ull> luck;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> k;
#endif 

	sum = 0;
	FORN(i, n)
	{
		cin >> l >> t ;
		if (!t)
		{
			sum += l;
		}
		else
		{
			luck.push(l);
		}
	}

	if (luck.size() <= k)
	{
		while (!luck.empty())
		{
			val = luck.top();
			luck.pop();
			sum += val;
		}
	}
	else
	{
		while (k-- && !luck.empty())
		{
			val = luck.top();
			luck.pop();
			sum += val;
		}

		while (!luck.empty())
		{
			val = luck.top();
			luck.pop();
			sum -= val;
		}
	}

	cout << sum << endl;
	luck = priority_queue<ull>();

	return 0;
}
