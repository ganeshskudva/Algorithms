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
	ull diff,n = 0, currDiff;
	ull i, j, k, cnt;
	set<ull> mySet;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n>>diff;
#endif 

	ull arr[n];
	MEM(arr, 0, n, ull);

	FORN(i, n)
	{
		cin >> arr[i];
		mySet.insert(arr[i]);
	}

	cnt = 0;
	currDiff = 0;
	for (i = 0; i < (n - 2); i++)
	{
		for (j = (n - 1); j >= 2 ; j--)
		{
			if ((arr[j] - diff) != (arr[i] + diff))
			{
				continue;
			}
			else
			{
				currDiff = (arr[j] + arr[i])/2;
				if(mySet.count(currDiff) != 0)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;

	return 0;
}
