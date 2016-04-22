#include <bits/stdc++.h>

typedef long long int ull;

#define MEM(a, b,c,d) memset(a, (b), c * sizeof(d))
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
	ull t = 0,max, sum,i;
	char val;
	std::string str;
	int count[26];
	
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
		val = '\0';
		max = 0;
		sum = 0;
		MEM(count, 0, 26, int);
		for (i = 0; i < str.length(); i++)
		{
			count[str[i] - 'a']++;

			if (max < count[str[i] - 'a'])
			{
				max = count[str[i] - 'a'];
				val = str[i];
			}
		}

		for (i = 0; i < 26; i++)
		{
			if (i != (val - 'a'))
			{
				sum += count[i];
			}
		}

		if (max == sum)
		{
			cout <<"YES"<<endl;
		}
		else
		{
			cout <<"NO"<<endl;
		}

	}

	return 0;
}
