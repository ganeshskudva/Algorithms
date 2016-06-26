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

void disp(double a, double b, double h)
{
			if (a < b)
			{
				printf("%0.6lf %0.6lf %0.6lf\n", a, b, (double)h);
			}
			else
			{
				printf("%0.6lf %0.6lf %0.6lf\n", b, a, (double)h);
			}
}

int main()
{
	ull t = 0,i,j, h, s;
	double a, b, power, area, squarertplus, squarertminus;

#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> h >> s;
		power = pow(h, 2);
		area = 4 * s;
		squarertplus = sqrt(power + area);
		squarertminus = sqrt(power - area);
		a = (squarertplus + squarertminus) / 2;
		b = squarertplus - a;

		if ((power - area) >= 0)
		{
			disp(a, b, (double)h);
		}
		else
		{
			cout << "-1"<<endl;
		}

	}

	return 0;
}
