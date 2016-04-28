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
	ull i = 0, max_bracket, open_idx, close_idx, max;
	bool matching_bracket = false;
	std::string str;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	getline(cin, str);
#endif 

	max_bracket = 0;
	open_idx = 0;
	close_idx = 0;
	max = 0;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			max_bracket++;
			if (max_bracket > max)
			{
				max = max_bracket;
				open_idx = i;
				matching_bracket = true;
			}
		}
		else if (str[i] == ')')
		{
			max_bracket--;
			if (matching_bracket)
			{
				close_idx = i;
				matching_bracket = false;
			}
		}
	}
	cout << str.substr((open_idx + 1), (close_idx - (open_idx + 1)))<<endl;;

	return 0;
}
