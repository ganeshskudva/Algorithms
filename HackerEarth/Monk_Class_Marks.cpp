/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/
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
	ull t = 0,i,j, val, size;
	string str;
	map<ull, vector<string> >marks;
	vector<string> vec;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> str;
		cin >> val;

		if (marks.find(val) == marks.end())
		{
			vec.clear();
			vec.push_back(str);
			marks[val] = vec;
		}
		else
		{
			vec.clear();
			vec = marks[val];
			vec.push_back(str);
			marks[val] = vec;
		}
	}

		for (map<ull, vector<string> >::reverse_iterator it = marks.rbegin(); it != marks.rend(); ++it)
		{
			vec = it->second;
			sort(vec.begin(), vec.end());
			size = vec.size();

			FORN(i, size)
			{
				cout << vec[i]<<" "<<it->first<<endl;
			}

		}
		marks.clear();
		vec.clear();

	return 0;
}
