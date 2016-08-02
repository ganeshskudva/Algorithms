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

ull findCandidate(ull a[], ull size)
{
    ull maj_index = 0, count = 1;
    ull i;
    for (i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
 
/* Function to check if the candidate occurs more than n/2 times */
ull isMajority(ull a[], ull size, ull cand)
{
    ull i, count = 0;
    for (i = 0; i < size; i++)
      if (a[i] == cand)
         count++;
    if (count > size/2)
       return count;
    else
       return 0;
}

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, cand, cnt, n;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> n;
		ull arr[n];
		MEM(arr, 0, n, ull);

		FORN(i, n)
		{
			cin >> arr[i];
		}
		cand = findCandidate(arr, n);

		cnt = isMajority(arr, n, cand);
		if (cnt)
		{
			cout << cnt << endl;
		}
		else
		{
			if (n & 1)
			{
				cout << (n/2) + 1 << endl;
			}
			else
			{
				cout << (n/2)<<endl;
			}
		}

	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
