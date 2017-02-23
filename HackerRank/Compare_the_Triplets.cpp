/*
* https://www.hackerrank.com/contests/esperanza17/challenges/compare-the-triplets
*/

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
#define CLOCK 0

bool isPrime(ull number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

static inline ull is_odd(ull x) { return x & 1; }

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, n, val, cntA, cntB;
	ull a[3], b[3];
	MEM(a, 0, 3, ull);
	MEM(b, 0, 3, ull);
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#endif 

	FORN(i, 3)
	{
		cin >> a[i];
	}

	FORN(i, 3)
	{
		cin >> b[i];
	}

	FORN(i, 3)
	{
		if (a[i] > b[i])
		{
			cntA++;
		}

		if (b[i] > a[i])
		{
			cntB++;
		}
	}

	cout << cntA <<" "<<cntB << endl;

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
