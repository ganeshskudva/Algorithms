/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/maximum-occurrence-9/
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
	ull t = 0,i,j, max, size, idx, cnt;
	string str;
	map<char, ull> counter;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	getline(cin, str);
#endif 

	size = str.size();
	FORN(i, size)
	{
		if (counter.find(str[i]) == counter.end())
		{
			counter[str[i]] = 1;
		}
		else
		{
			cnt = counter[str[i]];
			cnt++;
			counter[str[i]] = cnt;
		}
	}

	max = counter[0];
	idx = 0;
	for(i = 1; i<counter.size(); i++)
	{
		if (counter[i] > max)
		{
			max = counter[i];
			idx = i;
		}
	}

	map<char, ull>::iterator it = counter.begin();
	i = 0;
	while(i < idx)
	{
		++it;
		i++;
	}
	cout << it->first << " "<<it->second << endl;


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
