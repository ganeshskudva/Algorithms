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
#define NEG_MAX -100000000000

int main()
{
	ull t = 0,n, temp, i, curr_max, max_so_far;
	set<ull> excluded;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{	
		curr_max = 0;
		max_so_far = 0;
#if DEBUG
		n = (rand()%10)+1;
		cout <<n<<" ";
#else
		cin >> n;
#endif

		FORN(i, 4)
		{
#if DEBUG
			temp = (rand()%5)+1;
			cout << temp<<" ";
#else
			cin >> temp;
#endif
			excluded.insert(temp);
		}
#if DEBUG
		cout << endl;
#endif

		ull arr[n];
		MEM(arr, 0, n, ull);

		FORN(i, n)
		{
#if DEBUG
			arr[i] = (rand()%10)+1 - 5;
			cout <<arr[i] <<" ";
#else
			cin >> arr[i];
#endif

			temp = arr[i];
			if (excluded.count(arr[i]) != 0)
			{
				temp = NEG_MAX;
			}

			if (!i)
			{
				max_so_far = temp;
				curr_max = temp;
			}	
			else
			{
				curr_max = MAX(temp, (curr_max + temp));
				max_so_far = MAX(max_so_far, curr_max);
			}

		}
#if DEBUG
		cout << endl;
#endif
		excluded.clear();
		cout << max_so_far << endl;

	}

	return 0;
}
