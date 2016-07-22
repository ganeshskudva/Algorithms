/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/city-and-flood-1/
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
#define ROOT -1

ull get_root(ull arr[], ull i)
{
	while (arr[i] != i)
	{
		i = arr[i];
	}

	return i;
}

int main()
{
	ull t = 0,i,j, n, k, l, r, cnt, root, var;
	set<ull> seen;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> k;
#endif 

	ull arr[n], unionArr[n];
	MEM(arr, 0, n, ull);
	MEM(unionArr, 0, n, ull);

	FORN(i, n)
	{
		arr[i] = i;
	}

	while (k--)
	{
		cin >> l >> r;
		arr[r - 1] = l - 1;
	}

	root = ROOT;
	cnt = 0;

	FORN(i, n)
	{
		var = get_root(arr, i);

		if (seen.count(var) == 0)
		{
			cnt++;
			seen.insert(var);
		}
	}
	seen.clear();
	cout << cnt << endl;

	return 0;
}
