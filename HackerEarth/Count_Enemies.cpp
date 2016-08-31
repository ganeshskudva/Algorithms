/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/count-enemies-5/
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
	ull t = 0,i,j, size, cnt, n;
	string str;
	bool left, right;
	stack<char> cont;
	char c;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cnt = 0;
		cin >> str;
		size = str.size();
		n = size;

		FORN(i, size)
		{
			if (str[i] == 'X')
			{
				if (cont.empty())
				{
					cont.push(str[i]);
				}
				else
				{	
					do
					{
						c = cont.top();
						if (c == 'O')
						{
							cont.pop();
						}
					} while (c == 'O' && !cont.empty());
					cont.push(str[i]);
				}
			}
			else if (str[i] == 'O')
			{
				if (cont.empty())
				{
					cont.push(str[i]);
				}
				else
				{
					c = cont.top();
					if (c != 'X')
					{
						cont.push(str[i]);
					}
				}
			}
			else
			{
				cont.push(str[i]);
			}

		}

		cnt = 0;
		while (!cont.empty())
		{
			c = cont.top();
			if (c == 'O')
			{
				cnt++;
			}
			cont.pop();
		}
		cout << cnt << endl;
		stack<ull> cont = stack<ull>();
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
