/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/priyanka-and-toys?h_r=next-challenge&h_v=zen
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
	ull t = 0,i,j, n, val, cnt, init;
	vector<ull> vec;
#if DEBUG 
	srand((unsigned)time(0));
	n = (rand()%10)+1; 
	cout <<n<<endl;
#else 
	cin >> n;
#endif 

	FORN(i, n)
	{
#if DEBUG
		val = (rand()%10)+1; 
		cout << val << " ";
#else
		cin >> val;
#endif
		vec.push_back(val);
	}
#if DEBUG
	cout << endl;
#endif

	sort(vec.begin(), vec.end());
	cnt = 1;
	init = vec[0];
#if DEBUG
	cout << vec[0]<<" ";
#endif
	for(i = 1; i < n; i++)
	{
		if (vec[i] > (init + 4))
		{
			cnt++;
			init = vec[i];
#if DEBUG
			cout << vec[i]<<" ";
#endif
		}
	}
#if DEBUG
	cout << endl << endl;
#endif
	cout << cnt << endl;

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
