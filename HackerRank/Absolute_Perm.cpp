/*
* https://www.hackerrank.com/contests/may-world-codesprint/challenges/absolute-permutation
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
	ull t = 0,n,k, i;
	bool fail = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> n>>k;
		fail = false;
		ull arr[n + 1];
		MEM(arr, 0, (n+1), ull);
		if (k > (n/2))
		{
			cout <<"-1"<<endl;
			continue;
		}
		else if (k == 0)
		{
			FORAB(i, 1, n)
			{
				cout<<i<<" ";
			}
			cout<<endl;
			continue;
		}
		else 
		{
			for (i = 1; i <= k; i++)
			{
				arr[i + k] = i;
			}
			for (i = n; i > (n - k); i--)
			{
				if (arr[i - k])
				{
					cout <<"-1"<<endl;
					fail = true;
					break;
				}
				arr[i - k] = i;
			}

			for (i = (k+1); i<=(n-k); i++)
			{
				if ((arr[i - k]) && (arr[i + k]))
				{
					cout << "-1"<<endl;
					fail = true;
					break;
				}
				else if (!arr[i - k])
				{
					arr[i - k] = i;
				}
				else if (!arr[i + k])
				{
					arr[i + k] = i;
				}

			}
			if (!fail)
			{
				FORAB(i, 1,(n))
				{
					cout << arr[i]<<" ";
				}
				cout<<endl;
			}
		}

	}

	return 0;
}
