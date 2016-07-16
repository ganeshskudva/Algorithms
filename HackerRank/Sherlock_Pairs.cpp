/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/sherlock-and-pairs
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

int main()
{
	ull t = 0,i,j, n, val, size, sum, cnt;
	map<ull, ull> idxMap;
	vector<ull> vec;
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

		FORN(i, n)
		{
			cin >> val;

			if (idxMap.find(val) == idxMap.end())
			{
				idxMap[val] = 1;
			}
			else
			{
				cnt = idxMap[val];
				cnt++;
				idxMap[val] = cnt;
			}
		}

		sum = 0;
		for (map<ull,ull>::iterator it = idxMap.begin(); it != idxMap.end(); ++it)
		{
			cnt = it->second;

			if (cnt > 1)
			{
				sum += (cnt * (cnt - 1));
			}

		}
		cout << sum << endl;
		idxMap.clear();
		vec.clear();
	}

	return 0;
}
