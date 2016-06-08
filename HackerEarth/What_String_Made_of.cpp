/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/what-is-the-string-made-of-2/
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
	ull t = 0,i,j, cnt;
	string str;
	map <char, int> dashes;
	dashes.insert(pair<char,int>('0', 6));
	dashes.insert(pair<char,int>('1', 2));
	dashes.insert(pair<char,int>('2', 5));
	dashes.insert(pair<char,int>('3', 5));
	dashes.insert(pair<char,int>('4', 4));
	dashes.insert(pair<char,int>('5', 5));
	dashes.insert(pair<char,int>('6', 6));
	dashes.insert(pair<char,int>('7', 3));
	dashes.insert(pair<char,int>('8', 7));
	dashes.insert(pair<char,int>('9', 6));

#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> str;
#endif 
	cnt = 0;
	FORN(i, str.size())
	{
		cnt += dashes[str[i]];
	}
	cout << cnt << endl;
	return 0;
}
