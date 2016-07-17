/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/monk-and-champions-league/
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

int main()
{
	ull t = 0,i,j, m, n, val, sum, top;
	priority_queue<ull> tkt;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> m >> n;
#endif 

	FORN(i, m)
	{
		cin >> val;
		tkt.push(val);
	}

	sum = 0;
	i = 1;
	while(!tkt.empty())
	{
		top = tkt.top();
		tkt.pop();
		sum += top;
		top--;
		tkt.push(top);

		if (i == n)
		{
			break;
		}
		i++;
	}

	cout << sum << endl;

	return 0;
}
