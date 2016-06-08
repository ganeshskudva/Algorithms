/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/girlfriends-demands/
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
	ull t = 0,i,j, size;
	string str;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	getline(cin, str);
#endif 
	cin >> t;
	size = str.size();
	while (t--)
	{
		cin >> i>> j;
 
 		if (size == 1)
 		{
 			cout << "Yes"<<endl;
 		}
 		else
 		{
			if (str[(i - 1) % size] == str[ (j - 1) % size])
			{
				cout << "Yes"<<endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}

	}

	return 0;
}
