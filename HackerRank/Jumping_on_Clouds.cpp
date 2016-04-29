#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

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
	ull n = 0, i, cnt;
	ull cur_cloud = 0;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n;
#endif 

	ull arr[n];
	MEM(arr, 0, n, ull);
	
	FORN(i, n)
	{
		cin >> arr[i];
	}

	cur_cloud = 0;
	cnt = 0;
	i = 0;
	while(cur_cloud != (n - 1))
	{
		if (!arr[i + 2])
		{
			cur_cloud = i + 2;
			i = i + 2;
		}
		else
		{
			cur_cloud = i + 1;
			i++;
		}
		cnt++;
	}
	cout << cnt<<endl;

	return 0;
}
