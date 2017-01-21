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
#define WOMAN_LEN 5
#define MAN_LEN   3

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, vil = 1, sup = 1, cnt, size, win = 0;
	string str;
	bool done = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> cnt;
		sup = 1;
		vil = 1;
		win = 0;
		done = false;
		while (cnt--)
		{
			cin >> str;
			size = str.length();

			if (size >= WOMAN_LEN && ("woman" == str.substr(size - WOMAN_LEN)))
			{
				sup++;
			}
			else if ( size >= MAN_LEN && ("man" == str.substr(size - MAN_LEN)))
			{
				sup++;
			}
			else
			{
				vil++;
			}

			if (!done)
			{
				if ((sup - vil) == 2)
				{
					win = 1;
					done = true;
				}
				else if ((vil - sup) == 3)
				{
					win = 2;
					done = true;
				}
			}
		}


			if (!win)
			{
				cout << "draw"<<endl;
			}
			else if (win == 1)
			{
				cout << "superheroes"<<endl;
			}
			else if (win == 2)
			{
				cout << "villains"<<endl;
			}
		

	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
