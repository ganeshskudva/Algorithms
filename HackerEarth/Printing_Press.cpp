/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/arjit-and-printing-press/
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
       "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
#endif

int main()
{
	ull t = 0,i,j, sizeW, sizeR, size;
	string w, r, out;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{

#if DEBUG
		char buff[5];
		memset(buff, '\0', sizeof(char));
		gen_random(buff, sizeof(buff));
		w.assign(buff, sizeof(buff));
		memset(buff, '\0', sizeof(char));
		gen_random(buff, sizeof(buff));
		r.assign(buff, sizeof(buff));
		cout<<w<<endl<<r<< endl;
#else
		cin >> w >> r;
#endif
		sizeW = w.size();

		sort(r.begin(), r.end());

		FORN(i, sizeW)
		{
			FORN(j, r.size())
			{
				if ((r[j] - w[i]) < 0)
				{
					w[i] = r[j];
					r.erase(j, 1);
				}
			}
		}
		cout << w << endl;

	}

	return 0;
}
