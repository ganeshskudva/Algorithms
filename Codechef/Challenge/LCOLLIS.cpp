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

ull nCr(ull n, ull r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    ull ans = 1;
    ull i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void add_to_map(map<ull, ull> &collMap, ull key, ull val)
{
	if (collMap.find(key) == collMap.end())
	{
		collMap[key] = val;
	}
	else
	{
		collMap[key] += val;
	}
}

int main()
{
	ull t = 0,i,j, n, m, sum ;
	map <ull, ull> coll;
	string str;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 


	while (t--)
	{
		cin >> n >> m;
		ull arr[n][m];
		sum = 0;
		FORN(i , n)
		{
			cin >> str;

			FORN(j, m)
			{
				if (str[j] == '1')
				{
					add_to_map(coll, j, 1);
				}
				else
				{
					add_to_map(coll, j, 0);
				}
			}
		}

		map<ull, ull>::iterator it = coll.begin();
		for (; it != coll.end(); ++it)
		{
			if (it->second > 1)
			{
				sum += nCr(it->second, 2);
			}

		}

		cout << sum << endl;
		coll.clear();
	}

	return 0;
}
