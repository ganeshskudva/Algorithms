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

#if DEBUG
void gen_random(char *s, const int len) {

	int i;
	static const char alpha[] = "abcd";
    static const char alphanum[] =
        "           0 1    2 3 4 5 6 7 8 9";
//    static const char alphanum[] =
  //     "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < 5; i++)
    {
     	s[i] = alpha[rand() % (sizeof(alphanum) - 1)];
    }

    s[i++] = '$';
    for (; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
#endif

int main()
{
	ull t = 0, i, size;
	bool leading_digit_found = false;
	string input, output;
#if DEBUG
	ifstream file("HEtest.txt");
	ofstream outfile;
	outfile.open("HEtest_out.txt");
	string str;
#endif


#if DEBUG 
	getline(file, str);
	t = (ull)atoi(str.c_str());
	cout <<t<<endl;
#else 
	cin >> t;
	cin.ignore();
#endif 

	while (t--)
	{
		leading_digit_found = false;

#if DEBUG
		getline(file, input);
		cout << input<<endl<<endl;
#else
		getline(cin, input);
#endif
		size = input.size();
		FORN(i, size)
		{
			if (input[i] == '$')
			{
				break;
			}
		}

		while (i < size) 
		{
			if ((input[i] == '0') && leading_digit_found)
			{
				output.push_back(input[i]);
			}	
			if ((input[i] >= '1') && (input[i] <= '9'))
			{
				leading_digit_found = true;
				output.push_back(input[i]);
			}
			if (((input[i] >= 'a') && (input[i] <= 'z')) || ((input[i] >= 'A') && (input[i] <= 'Z')) )
			{
				break;
			}
			i++;
		}

		if (output.size() > 0)
		{
#if DEBUG
			outfile << "$" <<output<<endl;
#endif
			cout <<"$"<< output<<endl;
		}
		else
		{
#if DEBUG
			outfile << "$0" <<endl;
#endif
			cout <<"$0"<<endl;
		}
		output.clear();
	}

	return 0;
}
