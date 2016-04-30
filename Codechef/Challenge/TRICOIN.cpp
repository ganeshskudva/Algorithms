#include <bits/stdc++.h>

typedef unsigned long long int ull;

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

ull get_sum(ull n)
{
	return (n * (n + 1))/2;
}

int main()
{
	ull sum, n,t = 0, consecutive_sum;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		consecutive_sum = 0;
		cin >> sum;
		n = (ull)sqrt((double)sum);

		if (sum > get_sum(n))
		{
			do 
			{
				n++;
				consecutive_sum = get_sum(n);
			}while (sum > consecutive_sum);

			if (consecutive_sum == sum)
			{
				cout << n<<endl;
			}
			else
			{
				cout << n-1<<endl;
			}
		}
		else if (sum < get_sum(n))
		{
			do
			{
				n--;
				consecutive_sum= get_sum(n);
			}while (consecutive_sum > sum);

			if (consecutive_sum == sum)
			{	
				cout << n<<endl;
			}
			else
			{
				cout << n+1<<endl;
			}
		}
		else
		{
			cout << n<<endl;
		}
	}

	return 0;
}
