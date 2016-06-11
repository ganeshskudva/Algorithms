/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/code-hunt-2v/algorithm/color-code/
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

map <char, char> mars;


std::string convert_int(ull n)
{
   std::stringstream ss;
   ss << std::hex <<n;
   return ss.str();
}

string convert_martian(string str)
{
	ull i, size;
	string out;

	size = str.size();
	if (size < 2)
	{
		out.push_back('0');
	}
	FORN(i, size)
	{
		if (((str[i] >= 'a') && (str[i] <= 'f')) || ((str[i] >= 'A') && (str[i] <= 'Z')))
		{
			out.push_back(mars[str[i]]);
		}
		else
		{
			out.push_back(str[i]);
		}
	}

	return out;
}

int main()
{
	ull t = 0,i,j,r,g,b;
	string in, out;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	mars['a'] = 'U';
	mars['A'] = 'U';
	mars['b'] = 'V';
	mars['B'] = 'V';
	mars['c'] = 'W';
	mars['C'] = 'W';
	mars['d'] = 'X';
	mars['D'] = 'X';
	mars['e'] = 'Y';
	mars['E'] = 'Y';
	mars['f'] = 'Z';
	mars['F'] = 'Z';

	FORN(i, t)
	{
		cin >>r>>g>>b;
		cout << "Case "<<i+1<<": "<<convert_martian(convert_int(r))<<" "<<convert_martian(convert_int(g))<<" "<<convert_martian(convert_int(b))<<endl;
	}

	return 0;
}
