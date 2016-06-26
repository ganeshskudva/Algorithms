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

int main()
{
	ull t = 0,i,j, n, tmp, cnt, l, b;
	priority_queue<ull> sticks;
	map <ull, ull> stick_map;
	bool possible = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		possible = false;
		cin >> n;
		FORN(i, n)
		{
			cin >> tmp;
			sticks.push(tmp);
			if (stick_map.find(tmp) == stick_map.end())
			{
				stick_map[tmp] = 1;
			}
			else
			{
				cnt = stick_map[tmp];
				cnt++;
				stick_map[tmp] = cnt;
			}
		}

		l = 0;
		b = 0;
		while (!sticks.empty())
		{

			tmp = sticks.top();

			if (stick_map[tmp] >= 2)
			{
				cnt = stick_map[tmp];
				cnt -= 2;
				stick_map[tmp] = cnt;
				if (!l)
				{
					l = tmp;
				}
				else if (!b)
				{
					b = tmp;
				}

				if (l && b)
				{
					possible = true;
					break;
				}
			}
			sticks.pop();
		}

		if (possible)
		{
			cout << l * b << endl;
		}
		else
		{
			cout << "-1"<<endl;
		}
		stick_map.clear();
	}

	return 0;
}
