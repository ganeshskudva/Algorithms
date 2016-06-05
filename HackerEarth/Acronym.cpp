/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/acronym-2/
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
	ull t = 0, n, i;
	string temp, str, out;
	set<string> dislike;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		cin >> temp;
		dislike.insert(temp);
	}

	cin >> n;
	cin.ignore();
	getline(cin, str);

	std::vector<string> vec = split(str, " ");
	FORN(i, vec.size())
	{
		if (dislike.count(vec[i]) == 0)
		{
			temp = vec[i];
			out.push_back(toupper(temp[0]));
				out.append(".");

		}
	}
	out.pop_back();
	cout << out << endl;

	return 0;
}
