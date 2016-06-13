/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/where-have-the-vowels-gone-pledge-easy/
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
	ull t = 0,i,j;
	string str;
	bool found = true;
	map <char, bool> vowels;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t>> str;
#endif 

	vowels['a'] = false;
	vowels['e'] = false;
	vowels['i'] = false;
	vowels['o'] = false;
	vowels['u'] = false;

	FORN(i , t)
	{
		if (vowels.find(tolower(str[i])) != vowels.end())
		{
			vowels[tolower(str[i])] = true;
		}
	}

	found = true;
	for (map<char, bool>::iterator it = vowels.begin(); it != vowels.end(); it++)
	{
		if (it->second == false)
		{
			found = false;
			break;
		}
	}

	printf("%s\n", found?"YES":"NO");

	return 0;
}
