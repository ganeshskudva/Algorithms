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

#define MOD                     1000000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)

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
	ull t = 0,i,j, n, val, cnt, m, k, l, r, x, sum;
	string str;
	vector<ull> vec;
	set<ull> cont;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> m >> k;
#endif 

	vec.clear();
	cont.clear();
	FORN(i, n)
	{
		cin >> val;
		vec.pb(val);
	}

	FORN(i, k)
	{
		cin >> val;
		cont.insert(val);
	}

	while (m--)
	{
		cin >> l >> r >> x;
		sum = 0;

		for (i = l-1; i <= (r-1); i++)
		{
			if (cont.count(vec[i]) == 0)
			{
				val = vec[i] + x;
				vec[i] = val;
			}

			sum += vec[i];
		}

		for(i = r; i < n; i++)
		{
			sum += vec[i];
		}
		cout << sum << endl;
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
