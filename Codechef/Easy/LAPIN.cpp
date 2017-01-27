/*
* AUTHOR: Ganesh S Kudva
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
#define CLOCK 0

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, size, low, high;
	ull arr1[26], arr2[26];
	bool impossible = false;
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
		MEM(arr1, 0, 26, ull);
		MEM(arr2, 0, 26, ull);
		impossible = false;

		cin >> str;
		size = str.size();

		low = size/2;
		if (size & 1)
		{
			high = low + 1;
		}
		else
		{
			high = low;
		}

		FORN(i, low)
		{
			arr1[str[i] - 'a']++;
		}

		for(i = high; i < size; i++)
		{
			arr2[str[i] - 'a']++;
		}

		FORN(i, 26)
		{
			if (arr1[i] != arr2[i])
			{
				impossible = true;
				break;
			}
		}

		printf("%s\n", impossible?"NO":"YES");
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
