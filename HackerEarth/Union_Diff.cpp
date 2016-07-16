/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/code-hunt-2z/algorithm/satisfaction-sets/
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
#define MOD (1000000000)

int main()
{
	ull t = 0,i,j, n, val, unionSum, diffSum, power, cnt;
	set<ull> unionSet, diffSet, temp;
	map<ull, ull> freq;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%5)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	FORN(j, t)
	{	
#if DEBUG
		n = (rand()%10)+1;
		cout << n<<endl;
#else
		cin >> n;
#endif

		if (j)
		{
			FORN(i, n)
			{	
#if DEBUG
				val = (rand()%10)+1;
				cout << val<<" ";
#else
				cin >> val;
#endif
				unionSet.insert(val);
				if (diffSet.count(val) != 0)
				{	
					if (temp.count(val) == 0)
					{
						temp.insert(val);
						cnt = freq[val];
						cnt++;
						freq[val] = cnt;
					}
				}
				else
				{
					diffSet.insert(val);
					temp.insert(val);
					freq[val] = 1;
				}
			}
#if DEBUG
			cout << endl;
#endif
			temp.clear();
		}
		else
		{
			FORN(i, n)
			{
#if DEBUG
				val = (rand()%10)+1;
				cout << val << " ";
#else
				cin >> val;
#endif
				unionSet.insert(val);
				if (diffSet.count(val) == 0)
				{
					diffSet.insert(val);
					freq[val] = 1;
				}
			}
#if DEBUG 
			cout << endl;
#endif
		}
	}

	if (t > 1)
	{
		unionSum = 0;
		diffSum = 0;
		for(set<ull>::iterator it = unionSet.begin(); it != unionSet.end(); ++it)
		{
			unionSum += *it;
		}

		for(map<ull, ull>::iterator it = freq.begin(); it != freq.end(); ++it)
		{
			if (it->second != t)
			{
				diffSum += it->first;
			}
		}

		unionSet.clear();
		freq.clear();
	#if DEBUG
		cout << "diffSum:  "<<diffSum<<" unionSUm: "<<unionSum<<endl;
	#endif
		power = (diffSum - unionSum) % MOD;
		cout << power << endl;
	}
	else
	{
		cout << "0"<<endl;
	}

	return 0;
}
