/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/in-search-of-samosa-pledge-easy-3/
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
	ull t = 0,i,j, n, k, val, cnt, sum;
	priority_queue<ull, vector<ull>, greater<ull> > price;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> k;
#endif 

	while (n--)
	{
		cin >> val;
		price.push(val);
	}

	sum = 0;
	cnt = 0;
	while (!price.empty() && (sum <= k))
	{
		val = price.top();
		price.pop();
		if ((sum + val) <= k)
		{
			sum += val;
			cnt++;
		}
	}
	cout << cnt << endl;
	price = priority_queue<ull, vector<ull>, greater<ull> >();
	return 0;
}
