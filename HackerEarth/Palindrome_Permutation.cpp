/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/palindrome-check-2-1/
*
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

#if DEBUG
void gen_random(char *s, const int len) {
//    static const char alphanum[] =
//        "abcdefghijklmnopqrstuvwxyz";
    static const char alphanum[] =
       "abc";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
#endif

int main()
{
	ull t = 0,i,j, size, cnt_odd;
	string str;
	bool possible = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
		char buff[t];
		memset(buff, '\0', sizeof(char));
		gen_random(buff, sizeof(buff));
		str.assign(buff, sizeof(buff));
		cout<<str<<endl;
#else 
	cin >> str;
#endif 
	ull arr[26];
	MEM(arr, 0, 26, ull);
	possible = true;
	cnt_odd = 0;

	size = str.size();
	FORN(i, size)
	{
		arr[str[i] - 'a']++;
	}

	if (size & 1)
	{
		FORN(i, 26)
		{
			if (arr[i] & 1)
			{
				cnt_odd++;
				if (!(cnt_odd & 1))
				{	
					possible = false;
					break;
				}
			}

	
		}
	}
	else
	{
		FORN(i, 26)
		{
			if (arr[i] & 1)
			{
				possible = false;
				break;
			}
		}
	}

	printf("%s\n", possible?"YES":"NO");

	return 0;
}
