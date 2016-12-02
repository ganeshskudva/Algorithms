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
#define DUMMY_MIN 10000000

bool check( char ch)
{
	bool doCheck = false;

	if (ch == 'h')
	{
		doCheck = true;
	}

	if (ch == 'a')
	{
		doCheck = true;
	}

	if (ch == 'c')
	{
		doCheck = true;
	}

	if (ch == 'k')
	{
		doCheck = true;
	}

	if (ch == 'e')
	{
		doCheck = true;
	}

	if (ch == 'r')
	{
		doCheck = true;
	}

	if (ch == 't')
	{
		doCheck = true;
	}

	return doCheck;
}

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, size, min;
	string str;
	char in[26], match[26];
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
	cin >> str;
#endif 

	MEM(in, 0, 26, char);
	MEM(match, 0, 26, char);

	match['a' - 'a'] = 2;
	match['c' - 'a'] = 1;
	match['e' - 'a'] = 2;
	match['h' - 'a'] = 2;
	match['k' - 'a'] = 1;
	match['r' - 'a'] = 2;
	match['t' - 'a'] = 1;

	size = str.size();
	min = DUMMY_MIN;

	FORN(i, size)
	{
		in[str[i] - 'a']++;
	}

	FORN (i, 26)
	{
		if (check(i + 'a'))
		{
			if (in[i] >= match[i])
			{
				if (in[i] < min)
				{
					min = in[i];
				}
			}
			else
			{
				min = -1;
			}
		}
	}

	if (min < 0){
		printf("%d\n", 0);
	}
	else
	{
		printf("%lld\n", min);
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
