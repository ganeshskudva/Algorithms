/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/monks-choice-of-numbers-1/
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

ull bit_cnt(ull n)
{
	ull cnt = 0;

	while (n)
	{
		n &= (n - 1);
		cnt++;
	}

	return cnt;
}

int main()
{
	ull t = 0,i,j, n, k, val, bitcount, cnt;
	map<ull, vector<ull> > countMap;
	vector<ull> vec;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> n >> k;

		FORN(i, n)
		{
			cin >> val;
			bitcount = bit_cnt(val);

			if (countMap.find(bitcount) == countMap.end())
			{
				vec.clear();
				vec.push_back(val);
				countMap[bitcount] = vec;
			}
			else
			{
				vec = countMap[bitcount];
				vec.push_back(bitcount);
				countMap[bitcount] = vec;
			}
		}

		cnt = 0;
		bitcount = 0;
		for (map<ull, vector<ull> >::reverse_iterator rit = countMap.rbegin(); rit != countMap.rend(); ++rit)
		{
			if (cnt == k)
			{
				break;
			}
			vec = rit->second;
			if (vec.size() <= (k- cnt))
			{
				bitcount += rit->first * vec.size();
				cnt += vec.size();
			}
			else
			{
				bitcount += rit->first * (k - cnt);
				cnt += (k - cnt);
			}
		}

		cout << bitcount << endl;
		countMap.clear();
		vec.clear();
	}

	return 0;
}
