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

string get_activity()
{
	ull t = (rand()%4)+1; 
	string act;

	switch(t)
	{
		case 1: act = "CONTEST_WON";
				break;
		case 2: act = "TOP_CONTRIBUTOR";
				break;
		case 3: act = "BUG_FOUND";
				break;
		case 4: act = "CONTEST_HOSTED";
				break;
		default: break;

	}

	return act;
}

ull get_val(ull max)
{
	ull t = (rand()%max)+1;

	return t;
}

string get_nationality()
{
	ull t = (rand()%2)+1;

	if (t == 1)
	{
		return "INDIAN";
	}
	else
	{
		return "NON_INDIAN";
	}
}

int main()
{
	ull t = 0;
	ull act = 0, severity, rank, total, bug;
	string nationality, temp; 
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		total = 0;
		act = 0;
		rank = 0;
		bug = 0;
#if DEBUG 
		act = (rand()%10)+1;
		temp = get_nationality();
		cout <<act<<" "<<temp<<endl;
#else
		cin >> act >> temp;
#endif
		nationality = temp;
		while(act--)
		{	
#if DEBUG
			temp = get_activity();
			cout << temp <<" ";
#else
			cin >> temp;
#endif
			if (temp == "CONTEST_WON")
			{
#if DEBUG
				rank = get_val(5000);
				cout<< rank<<endl;
#else
				cin >> rank;
#endif
				if (rank < 20)
				{
					total = total + 300 + (20 - rank);
				}
				else
				{
					total += 300;
				}
			}
			if (temp == "TOP_CONTRIBUTOR")
			{
				total += 300;
			}
			if (temp == "BUG_FOUND")
			{
#if DEBUG
				bug = get_val(1000);
				cout << bug<<endl;
#else
				cin >> bug;
#endif
				total += bug;
			}
			if (temp == "CONTEST_HOSTED")
			{
				total += 50;
			}

#if DEBUG
			cout << endl;
#endif

		}
#if DEBUG 
			cout <<"Total is "<<total<<endl;
#endif

			if (nationality == "INDIAN")
			{
				cout << (total/200) <<endl;
			}
			else
			{
				cout << (total/400) <<endl;
			}
#if DEBUG
			cout <<endl<<endl;
#endif
	}

	return 0;
}
