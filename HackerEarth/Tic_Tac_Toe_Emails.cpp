/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/dcode3/algorithm/tic-tac-toe-emails/
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

vector<string> split(string data, string token)
{
    vector<string> output;
    int pos = string::npos;
    do
    {
        pos = data.find(token);
        output.push_back(data.substr(0, pos));
        if (string::npos != pos)
            data = data.substr(pos + token.size());
    } while (string::npos != pos);
    return output;
}

int main()
{
	ull t = 0, i, j,size;
	ull a, b;
	string str, out, temp;
	string space = " ";
	set<string> dups;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	vector<string> list;

	cin.ignore();
	while (t--)
	{

		getline(cin, str);
		size = str.size();

		vector<string> vec_str = split(str, " ");
		FORN(i, vec_str.size())
		{
			if (dups.count(vec_str[i]) == 0)
			{
				dups.insert(vec_str[i]);
				out.append(vec_str[i]);
				out.append(" ");
			}
		}
		cout << out << endl;
		out.clear();
		dups.clear();
		vec_str.clear();

	}

	return 0;
}
