/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/contests/hourrank-9/challenges/fair-rations
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
	ull n = 0,i, cnt, even_cnt;
	bool cant = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<n<<endl;
#else 
	cin >> n;
#endif 
		ull arr[n];
		MEM(arr, 0, n, ull);
	even_cnt = 0;

	FORN(i, n)
	{
		cin >> arr[i];
		if ((arr[i] & 1) == 0)
		{
			even_cnt++;
		}
	}

	if (even_cnt == n)
	{
		cout << "0"<<endl;
	}
	else
	{
		cnt = 0;
//		even_cnt = 0;
		cant = false;
			FORN(i, n)
			{
				if ((arr[i] & 1) )
				{
					if ((i + 1) >= n)
					{
						cant = true;
					}
					else
					{
						arr[i] += 1;
						arr[i+1] += 1;
						cnt += 2;
					}
				}
									
			}
		if (cant)
		{
			cout <<"NO"<<endl;
			
		}
		else
		{
			cout << cnt << endl;
		}
	}


	return 0;
}
