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
	map<char, ull> count;
	bool impossible = false;
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
		impossible = false;
		count.clear();

		FORN(i, size)
		{
			if (count.find(tolower(str[i])) == count.end())
			{
				count[tolower(str[i])] = 1;
			}
			else
			{
				cnt = count[tolower(str[i])];
				cnt++;
				count[tolower(str[i])] = cnt;
			}
		}

		cnt = 0;
		for (auto it = count.begin(); it != count.end(); ++it)
		{
			if (is_odd(it->second))
			{
				cnt++;
			}
		}

		if (is_odd(size))
		{

			if (cnt > 1)
			{
				impossible = true;
			}
		}
		else
		{	
			if (cnt > 0)
			{
				impossible = true;
			}
		}	

		printf("%s\n", impossible?"No":"Yes");
	}


#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
