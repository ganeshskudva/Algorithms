/*
* AUTHOR: Ganesh S Kudva
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>

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
	ull t = 0,i,j, n, val, size, sum, prev_ch_cnt;
	vector<ull> vec;
	string str;
	char ch = 'a', prev_ch;
	map<char, int> wght;
	set<ull> tots;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> str;
	cin >> t;
#endif 

	for(i = 1; i <= 26; i++)
	{
		wght[ch] = i;
		ch++;
	}

	sum = -1;
	size = str.size();
	FORN(i, size)
	{
		if (i)
		{
			if (str[i] == prev_ch)
			{
				prev_ch_cnt++;
			}
			else
			{
				prev_ch = str[i];
				prev_ch_cnt = 1;
			}
		}
		else
		{
			prev_ch = str[i];
			prev_ch_cnt = 1;
		}
		tots.insert(wght[prev_ch] * prev_ch_cnt);
	}

	tots.insert(wght[prev_ch] * prev_ch_cnt);


	while (t--)
	{
		cin >> val;

		if (tots.count(val) != 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
