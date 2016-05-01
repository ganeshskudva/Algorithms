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

bool contain_substr(string strA, string strB)
{	
	ull lenA, lenB, i;

	lenA = strA.size();
	lenB = strB.size();
	bool contains = false;
	size_t found = 0;

	if (lenA > lenB)
	{
		FORN(i, lenB)
		{
			found = strA.find(strB[i]);
			if (found != string::npos)
			{
				contains = true;
				break;
			}
		}		
	}
	else
	{
		FORN(i, lenA)
		{
			found = strB.find(strA[i]);
			if (found != string::npos)
			{
				contains = true;
				break;
			}
		}
	}

	return contains;
}

int main()
{
	ull t = 0, i, j;
	string strA, strB;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> strA>>strB;

		printf("%s\n",contain_substr(strA, strB)?"YES":"NO");
	}

	return 0;
}
