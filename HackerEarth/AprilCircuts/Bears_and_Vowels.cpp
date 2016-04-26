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
#define INFINITE 100000

using namespace std;

#define DEBUG 0

int is_vowel(char c)
{
	int vowel = 0;

	if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || c == 'y')
	{
		vowel = 1;
	}

	return vowel;
}

int main()
{
	ull t = 0, i;
	std::string str;
	ull vow_cnt, conso_cnt, conso_contiguous_cnt;
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
		vow_cnt = 0;
		conso_cnt = 0;
		conso_contiguous_cnt = 0;

		for (i = 0; i < str.length(); i++)
		{
			if (is_vowel(str[i]))
			{
				vow_cnt++;
				conso_contiguous_cnt = 0;
			}
			else
			{
				conso_cnt++;
				conso_contiguous_cnt++;
			}

			if (conso_contiguous_cnt == 3)
			{
				conso_cnt = INFINITE;
			}
		}

		if (conso_cnt > vow_cnt)
		{
			cout << "hard"<<endl;
		}
		else
		{
			cout << "easy"<<endl;
		}
	}

	return 0;
}
