#include <bits/stdc++.h>

typedef long long int ull;

#define MEM(a, b) memset(a, (b), sizeof(a))
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
	ull t = 0, a = 0, b = 0,i;

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
		a = ((rand()%20)+1)/2;
		b = ((rand()%20)+1)/2;
		cout << a<<" "<<b<<endl;
#else
		cin >>a>>b;
#endif
		if (!(a%2) || !(b%2))
		{
			cout << "Tuzik"<<endl;
		}
		else
		{
			cout<<"Vanka"<<endl;
		}


	}

	return 0;
}
