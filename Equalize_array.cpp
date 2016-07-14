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
#define DUMMY_MAX -1000000

int main()
{
	ull t = 0,i,j, n, cnt, val, max;
	map<ull, ull> arr;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	FORN(i, t)
	{
		cin >> val;

		if (arr.find(val) == arr.end())
		{
			arr[val] = 1;
		}
		else
		{
			cnt = arr[val];
			cnt++;
			arr[val] = cnt;
		}

	}

		max = DUMMY_MAX;
		for(map<ull, ull>::iterator it = arr.begin(); it != arr.end(); ++it)
		{
			val = it->second;
			if (val > max)
			{
				max = val;
			}
		}

		cout << t - max << endl;
		arr.clear();

	return 0;
}
