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

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, n, val, ecnt, ocnt, player, lose;
	vector<ull> vec;
	string str;
	priority_queue<ull> even, odd;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
#if DEBUG
		n = (rand()%10)+1; 
		if (n&1)
		{
			str = "Dee";
		}
		else
		{
			str = "Dum";
		}
		cout << n <<" "<< str<< endl;
#else
		cin >> n;
		cin >> str;
#endif
		priority_queue<ull> even = priority_queue<ull>();
		priority_queue<ull> odd = priority_queue<ull>();

			if (str == "Dee")
			{
				player = 2;
			}
			else
			{
				player = 1;
			}
		ecnt = 0;
		ocnt = 0;


		FORN(i, n)
		{
#if DEBUG
			val = (rand()%10)+1; 
			cout << val << " ";
#else
			cin >> val;
#endif


			if (val & 1)
			{
				ocnt++;
				odd.push(val);
			}
			else
			{
				ecnt++;
				even.push(val);
			}

		}
#if DEBUG
		cout << endl;
#endif
		if ((n== 1) && (ecnt == 1) && (player == 2))
		{
			cout << "Dee" << endl;
		}
		else
		{
			cout << "Dum" << endl;
		}
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
