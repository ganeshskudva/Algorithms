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

int main()
{
	ull t = 0,i,j,val, cnt, k, n;
	map<ull, ull> counter;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
#if DEBUG
		n = (rand()%10)+1;
		k = (rand()%n)+1;
		cout << n << " "<< k << endl;
#else
		cin >> n >> k;
#endif

		FORN(i, n)
		{
#if DEBUG
			val = (rand()%n)+1;
			cout << val << " ";
#else
			cin >> val;
#endif

			if ((i+1) != val)
			{
				if (counter.find(val) == counter.end())
				{
					counter[val] = 1;
				}
				else if (counter[val] != -1)
				{
					cnt = counter[val];
					cnt++;
					counter[val] = cnt;
				}
			}
			else
			{
				counter[val] = -1;
			}
		}
#if DEBUG
		cout << endl;
#endif
		cnt = 0;
		for(map<ull, ull>::iterator it = counter.begin(); it != counter.end(); ++it)
		{
			if (it->second >= k)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
		counter.clear();
	}

	return 0;
}
