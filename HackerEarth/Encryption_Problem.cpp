/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/hpemastermaze/problems/d5a82317012740f9aa327930f8e5ef74/
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
	ull t = 0,i,j, size, cnt;
	string str, out;
	map<char, ull> freq;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> str;
#endif 

	size = str.size();

	FORN(i, size)
	{
		if (freq.find(str[i]) == freq.end())
		{
			freq[str[i]] = 1;
		}
		else
		{
			cnt = freq[str[i]];
			cnt++;
			freq[str[i]] = cnt;
		}
	}

	FORN(i, size)
	{
		if (freq.find(str[i]) != freq.end())
		{
			out.push_back(str[i]);
			out.push_back(freq[str[i]] + '0');
			freq.erase(str[i]);
		}
	}

	cout << out << endl;

	return 0;
}
