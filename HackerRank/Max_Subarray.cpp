/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/maxsubarray/problem
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
	ull t = 0,i,j, n, val, cnt, sum, max_ending_here, max_so_far;
	string str;
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
		cin >> n;
		sum = 0;
		max_so_far = 0;
		max_ending_here = 0;
		vec.clear();
		FORN(i, n)
		{
			cin >> val;

			vec.push_back(val);
			if (i)
			{
				max_so_far = MAX(vec[i], max_so_far + vec[i]);
				max_ending_here = MAX(max_so_far, max_ending_here);
			}
			else
			{
				max_so_far = vec[0];
				max_ending_here = vec[0];
			}

			if (vec[i] > 0)
			{
				sum += vec[i];
			}
		}

		if (max_ending_here < 0)
		{
			sum = max_ending_here;
		}
		cout << max_ending_here << " "<< sum << endl;

	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
