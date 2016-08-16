/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/contests/w22/challenges/box-moving
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
#define CLOCK 0

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, n, val, sumx, sumy, calc;
	vector<ull> vex, vey;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n;
#endif 

	sumx = 0;
	sumy = 0;
	FORN(i, n)
	{
		cin >> val;
		vex.push_back(val);
		sumx += val;
	}

	FORN(i, n)
	{
		cin >> val;
		vey.push_back(val);
		sumy += val;
	}

	if (sumx != sumy)
	{
		cout << "-1" << endl;
		return 0;
	}

	sort(vex.begin(), vex.end());
	sort(vey.begin(), vey.end());
	calc = 0;
	FORN(i, n)
	{
		calc += abs(vey[i] - vex[i]);
	}

	cout << calc/2 << endl;

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
