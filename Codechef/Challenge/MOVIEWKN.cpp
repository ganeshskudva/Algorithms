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
	ull t = 0, n = 0,i = 0;
	ull max, maxL, maxR, index;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		max = 0;
		maxL = 0;
		maxR = 0;
		index = 0;
#if DEBUG
		n = (rand()%10)+1; 
		cout <<n<<endl;
#else
		cin >> n;
#endif
		ull arrL[n], arrR[n];
		MEM(arrL, 0, n, ull);
		MEM(arrR, 0, n, ull);

		for (i = 0; i < n; i++)
		{
#if DEBUG
			arrL[i] = (rand()%10)+1;
			cout << arrL[i]<<" ";
#else
			cin >> arrL[i];
#endif
		}

		for (i = 0; i < n; i++)
		{
#if DEBUG
			arrR[i] = (rand()%10)+1;
			cout << arrR[i]<<" ";
#else
			cin >> arrR[i];
#endif
		}

		for (i = 0; i < n; i++)
		{
			if (max < (arrL[i] * arrR[i]))
			{
				max = arrL[i] * arrR[i];
				maxL = arrL[i];
				maxR = arrR[i];
				index = i;
			}
			else if (max == (arrL[i] * arrR[i]))
			{	
				if (maxR < arrR[i])
				{
					maxL = arrL[i];
					maxR = arrR[i];
					index = i;
					continue;
				}				
				else if ((maxL > arrL[i]))
				{
					maxL = arrL[i];
					maxR = arrR[i];
				}
			}
		}
		cout << index + 1 << endl;

	}

	return 0;
}