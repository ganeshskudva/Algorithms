/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/INTEG
*/

#include<bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef __int64 LL;

vector<int> V;

int main()
{
	int n, i, a, x;
	long long cost, last;

	scanf("%d", &n);
	IN(n, 1, 100000);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &a);
		IN(a, -1000000000, 1000000000);
		if(a<0) V.push_back(-a);
	}

	sort(V.begin(), V.end());

	scanf("%d", &x);
	IN(x, 0, 1000000000);

	if(x >= V.size()) last = 0;
	else last = V[V.size()-x-1];

	cost = last*x;
	for(i = MAX(0, (int)V.size() - x); i < V.size(); i++)
	{
		cost += V[i] - last;
	}

	printf("%lld\n", cost);

	return 0;
}
