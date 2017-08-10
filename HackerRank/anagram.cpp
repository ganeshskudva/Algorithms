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

#define MOD                     1000000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)

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

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, n, val, cnt, size;
	string str;
	vector<ull> vec;
	unordered_map<char, ull> countA, countB;
	bool midWay, impossible;
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
		size = str.size();

		if (is_odd(size))
		{
			cout << "-1" << endl;
		}
		else
		{
			countA.clear();
			countB.clear();
			midWay = false;

			FORN(i, size)
			{
				if (i == (size/2))
				{
					midWay = true;
				}

				if (midWay)
				{
					countB[str[i]]++;
				}
				else
				{
					countA[str[i]]++;
				}

				cnt = 0;
				for (auto it = countB.begin(); it != countB.end(); ++it)
				{
					if (countA.find(it->first) == countA.end())
					{
						val = 0;
					}
					else
					{
						val = countA[it->first];
					}

					if (val < it->second)
					{
						cnt += (it->second - val);
					}
				}
			}

			cout << cnt << endl;
		}

	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
