/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/numbers-of-interest-1/
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
#define CLOCK 0

ull sum (vector<ull> &vec, ull idx, ull x)
{
	ull sumtotal = 0, index = 0;

	index = idx + x - 1;

	while (x--)
	{
		sumtotal += vec[index];
		index--;
	}

	return sumtotal;
}

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, x, y, n;
	vector<ull> vec;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> x >> y >> n;

		FORN(i, x)
		{
			vec.push_back(y);
		}

		n -= x;

		FORN(i, n)
		{
			vec.push_back(sum(vec, i, x));
		}

		cout << vec[vec.size() - 1]<<endl;
		vec.clear();
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
