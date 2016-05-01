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
	ull t = 0, i, j, idx;
	ull mismatchI_pos, mismatchJ_pos;
	ull tempi, tempj;
	bool palin = false;
	string str;
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
		palin = false;
 		j = str.size() - 1;
		i = 0;
		while (i < j)
		{
			if (str[i] != str[j])
			{
				break;
			}
			i++;
			j--;
		}

		if (i >= j)
		{
			palin = true;
			cout << -1<<endl;
		}

		if (!palin)
		{
			mismatchJ_pos = j;
			mismatchI_pos = i;
			tempj = j - 1;
			idx = j;
			tempi = i;

			while (tempi < tempj)
			{
				if (str[tempi] != str[tempj])
				{
					break;
				}
				tempi++;
				tempj--;
			}

			if (tempi >= tempj)
			{
				cout <<idx<<endl;
				continue;
			}
			else
			{
				tempi = mismatchI_pos + 1;
				idx = mismatchI_pos;
				tempj = mismatchJ_pos;

				while (tempi < tempj)
				{
					if (str[tempi] != str[tempj])
					{
						break;
					}
					tempi++;
					tempj--;
				}
				cout << idx<<endl;
			}
		}
	}


	return 0;
}
