/*
* AUTHOR: Ganesh S Kudva
* http://www.spoj.com/problems/ARMY/
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

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, ng, nm, val, out;
	vector<ull> ngpq, nmpq;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> ng >> nm;
		ngpq.clear();
		nmpq.clear();

		FORN(i, ng)
		{
			cin >> val;
			ngpq.push_back(val);
		}

		FORN(i, nm)
		{
			cin >> val;
			nmpq.push_back(val);
		}

		sort(ngpq.begin(), ngpq.end());
		sort(nmpq.begin(), nmpq.end());

		i = ng -1;
		j = nm - 1;
		out = -1;

		do
		{
			if (ngpq[i] < nmpq[j])
			{
				out = 2;
				break;
			}
			else if (nmpq[j] <= ngpq[i])
			{
				out = 1;
				break;
			}
		}while (i && j);

		if (out == 1)
		{
			cout << "Godzilla" << endl;
		}
		else
		{
			cout << "MechaGodzilla" << endl;
		}
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
