/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/jim-and-the-orders
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
#define CLOCK 0

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, s, e, size;
	map<ull, vector<ull> > timer;
	vector<ull> vec;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	FORN(i, t)
	{
		cin >> s >> e;

		if (timer.find(s+e) == timer.end())
		{
			vec.clear();
			vec.push_back(i+1);
			timer[s+e] = vec;
		}
		else
		{
			vec = timer[s+e];
			vec.push_back(i+1);
			timer[s+e] = vec;
		}
	}

		for(map<ull, vector<ull> >::iterator it = timer.begin(); it != timer.end(); ++it)
		{
			vec = it->second;
			size = vec.size();

			FORN(i, size)
			{
				cout << vec[i] << " ";
			}
		}
		cout << endl;

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
