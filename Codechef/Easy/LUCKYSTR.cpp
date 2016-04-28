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
	ull n,k = 0, i,j;
	bool good = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> k>>n;
#endif 

//	std::vector<string> fav = {k, 0};
//	std::vector<string> str = {n, 0};

	std::string fav[k];
	std::string str;
//	MEM(fav, '\0', k, string);
//	MEM(fav, '\0', k, string);

	FORN(i, k)
	{
		cin >> fav[i];
	}


	FORN(i, n)
	{
		good = false;
		cin >> str;
		if (str.size() >= 47)
		{
			good = true;
			cout << "Good"<<endl;
			continue;
		}
		else 
		{	
			FORN(j, k)
			{
				if (str.find(fav[j]) != std::string::npos)
				{
					good = true;
					cout << "Good"<<endl;
					break;
				}
			}
		}
		
		if (!good)
		{
			cout << "Bad"<<endl;
		}
	}

	return 0;
}
