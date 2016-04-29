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

int main()
{
	ull l,d,s,c, sum, d2, t;
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
		cin >> l>>d>>s>>c;
		d2 = s + (s *c);

		switch (d)
		{
			case 1: if (s >= l)
					{
						cout << "ALIVE AND KICKING" << endl;
					}
					else
					{
						cout << "DEAD AND ROTTING" << endl;
					}
					break;
			case 2: if (d2 >= l)
					{
						cout << "ALIVE AND KICKING" << endl;
					}
					else
					{
						cout << "DEAD AND ROTTING" << endl;
					}
					break;
			default: d -= 2;
					 while (d--)
					 {
					 	sum = d2 + (d2 * c);
					 	if (sum >= l)
					 	{
					 		break;
					 	}
					 	d2 = sum; 
					 }
					if (sum >= l)
					{
						cout << "ALIVE AND KICKING" << endl;
					}
					else
					{
						cout << "DEAD AND ROTTING" << endl;
					}
					break;
		}
	}

	return 0;
}
