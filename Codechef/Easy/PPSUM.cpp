#include <bits/stdc++.h>

typedef long long int ull;

#define MEM(a, b) memset(a, (b), sizeof(a))
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

ull calc_sum(ull n)
{
	ull i, sum = 0;

	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

int main()
{
	ull t = 0, sum = 0;
	ull iteration = 0, n = 0;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		sum = 0;
#if DEBUG
		iteration = (rand()%10)+1; 
		n = (rand()%10)+1; 
		cout << iteration <<" "<<n<<endl;
#else
		cin >> iteration >> n;
#endif

		sum = n;
		do 
		{
			sum = calc_sum(sum);
			iteration--;
		}while(iteration > 0);

		cout << sum<<endl;

	}

	return 0;
}
