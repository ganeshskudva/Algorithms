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

int main()
{
	ull t = 0, i;
	string str;
	bool is_pangram = true;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	getline(cin, str);
#endif 

	ull arr[26];
	MEM(arr, 0, 26, ull);

	FORN(i, str.size())
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			arr[str[i] - 'A']++;
		}
		else if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			arr[str[i] - 'a']++;
		}
	}

	FORN(i, 26)
	{
		if (!arr[i])
		{
			is_pangram = false;
			break;
		}
	}
	if (is_pangram)
	{
		cout<<"pangram"<<endl;
	}
	else
	{
		cout<<"not pangram"<<endl;
	}

	return 0;
}
