/*
* https://www.hackerrank.com/contests/may-world-codesprint/challenges/compare-the-triplets
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

ull greatVal(ull x, ull y)
{
	ull ret = 0;
	
	if (x > y)
	{
		ret = 1;
	}
	else if (x < y)
	{
		ret = 2;
	}
	else if (x == y)
	{
		ret = 0;
	}

	return ret;

}

void inc(ull val, ull &aCnt, ull &bCnt)
{
	switch(val)
	{
		case 1: aCnt++;
				break;
		case 2: bCnt++;
				break;
		default: break;
	}
}

int main()
{
	ull a0, a1,a2, b0, b1, b2 = 0;
	ull aCnt = 0, bCnt = 0, val;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> a0>>a1>>a2;
	cin>>b0>>b1>>b2;
#endif 

	val = greatVal(a0, b0);
	inc(val, aCnt, bCnt);

	val = greatVal(a1, b1);
	inc(val, aCnt, bCnt);

	val = greatVal(a2, b2);
	inc(val, aCnt, bCnt);

	cout << aCnt<<" "<<bCnt<<endl;

	return 0;
}
