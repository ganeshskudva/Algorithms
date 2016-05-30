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

ull ret_int(char c)
{
	int ret_val = 0;

	if ((c >= 'A') && (c <= 'Z'))
	{
		ret_val = c -'A';
	}
	else if ((c >= 'a') && (c <= 'z'))
	{
		ret_val = c -'a' + 26;
	}
	else if ((c >= '0') && (c <= '9'))
	{
		ret_val = c -'0' + 52;
	}

	return ret_val;
}

int main()
{
	ull t = 0, i, cnt;
	int val;
	string A, B;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	ull arrA[62];

	MEM(arrA, 0, 62, ull);


	while (t--)
	{
		cnt = 0;
		cin >> A>>B;

		FORN(i, (A.size()))
		{
			arrA[ret_int(A[i])]++;
		}

		FORN(i, (B.size()))
		{
			val = ret_int(B[i]);
			if (arrA[val])
			{
				cnt++;
				arrA[val]--;
			}
		}

		cout << cnt << endl;
		MEM(arrA, 0, 62, ull);
	}

	return 0;
}
