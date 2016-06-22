/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/two-arrays
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
	ull t = 0,i,j, n, k, val;
	std::vector<ull> inc, dec;
	bool impossible = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> n >> k;

		impossible = false;
		FORN(i, n)
		{
			cin >> val;
			inc.push_back(val);
		}

		FORN(i, n)
		{
			cin >> val ;
			dec.push_back(val);
		}

		sort(inc.begin(), inc.end());
		sort(dec.begin(), dec.end(), std::greater<ull>());

		FORN(i, n)
		{
			if ((inc[i] + dec[i]) < k)
			{
				impossible = true;
				break;
			}
		}

		printf("%s\n", impossible?"NO":"YES");
		inc.clear();
		dec.clear();
	}



	return 0;
}
