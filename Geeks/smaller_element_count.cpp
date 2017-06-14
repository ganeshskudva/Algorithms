/*
* AUTHOR: Ganesh S Kudva
* Given an sorted array of size n. Find number of elements which are less than or equal to given element.
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

bool isPrime(ull number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

static inline ull is_odd(ull x) { return x & 1; }

ull getCount(vector<ull>& vec, ull n)
{
	ull cnt = 0, size, low, high, mid, i;
	bool found = false;

	size = vec.size();
	low = 0;
	high = size - 1;
	mid = (low + high)/2;

	if (n > vec[size-1])
	{
		cnt = size;
	}
	else 
	{
		while (low <= high)
		{
			if (vec[mid] == n)
			{
				found = true;
				break;
			}
			else if (vec[mid] > n)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
			mid = (low+high)/2;
		}

		if (found)
		{
			cnt += (mid - 0);
			for (i = mid+1; i < size; i++)
			{
				if (vec[i] == n)
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
		}
	}

	return cnt;
}

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, n, val, cnt;
	string str;
	vector<ull> vec;
#if DEBUG
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else
	cin >> t;
#endif
 

	FORN(i, t)
	{
#if DEBUG
		val = (rand()%20)+1;
		cout << val <<" "; 
#else
		cin >> val;
#endif
		vec.push_back(val);
	}
#if DEBUG
	cout << endl;
#endif

	sort(vec.begin(), vec.end());
#if DEBUG
	val = (rand()%20)+1;
	cout << val << endl;
#else
	cin >> val;
#endif
	cout << getCount(vec, val) << endl;


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
