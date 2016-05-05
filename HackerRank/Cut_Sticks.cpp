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
#define LARGE 10000001

int main()
{
	ull i,cnt,n = 0,min,new_min, total_cut, sum;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n;
#endif 

	ull arr[n];
	MEM(arr, 0, n, ull);
	cnt = 0;
	min = LARGE;

	FORN(i, n)
	{
		cin >> arr[i];
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	total_cut = 0;
	new_min = LARGE;
	sum = LARGE;
	while (sum)
	{
		sum = 0;
		FORN(i, n)
		{
			if (arr[i] > 0)
			{
				arr[i] -= min;
				cnt++;
				if (arr[i] && (arr[i] < new_min))
				{
					new_min = arr[i];
				}
			}
			sum += arr[i];
		}
		cout << cnt<<endl;
		cnt = 0;
		min = new_min;
		new_min = LARGE;
	}

	return 0;
}
