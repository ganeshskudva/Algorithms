/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/sansa-and-xor
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
	ull t = 0,i,j, n, tmp, sum ;
	std::vector<ull> v,comb;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	sum = 0;
	while (t--)
	{
		sum = 0;
		cin >> n;

		FORN(i, n)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		if (n & 1)
		{
			for(i = 0; i < v.size(); i += 2)
			{
				sum ^= v[i];
			}
		}

		cout << sum << endl;
		v.clear();
        
	}

	return 0;
}
