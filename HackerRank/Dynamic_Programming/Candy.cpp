#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

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
	ull t = 0, n, i, sum;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<n<<endl;
#else 
	cin >> n;
#endif 


		sum = 0;
		ull rating[n], left[n];
		MEM(rating, 0, n, ull);
		MEM(left, 0, n, ull);
		
		left[0] = 1;
		FORN(i, n)
		{
			cin >> rating[i];
		}

		FORAB(i, 1,n)
		{
			if (rating[i] > rating[i - 1])
			{
				left[i] = left[i - 1] + 1;
			}
			else
			{
				left[i] = 1;
			}
		}

		for(i = (n - 2); i >=0; i--)
		{
			if (rating[i] > rating[i + 1])
			{
				left[i] = MAX(left[i], (left[i + 1] + 1));
			}
		}

		FORN(i, n)
		{
			sum += left[i];
		}

		cout << sum <<endl;


	return 0;
}
