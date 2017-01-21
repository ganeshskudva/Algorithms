/*
* AUTHOR: Ganesh S Kudva
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>

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

int main()
{
#if CLOCK
	clock_t tStart = clock();
#endif
	ull t = 0,i,j, m,n, val, size, cnt;
	string mag, note;
	map<string, ull> counter, count;
	bool impossible = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> m >> n;
#endif 

	vector<string> mag_vec(m), note_vec(n);

	FORN(i, m)
	{
		cin >> mag_vec[i];
	}

	FORN(i, n)
	{
		cin >> note_vec[i];
	}



  	size = note_vec.size();
  	FORN(i, size)
  	{
  		if (counter.find(note_vec[i]) == counter.end())
  		{
  			counter[note_vec[i]] = 1;
  		}
  		else
  		{
  			cnt = counter[note_vec[i]];
  			cnt++;
  			counter[note_vec[i]] = cnt;
  		}
  	}

  	size = mag_vec.size();
  	FORN(i, size)
  	{
  		if (count.find(mag_vec[i]) == count.end())
  		{
  			count[mag_vec[i]] = 1;
  		}
  		else
  		{
  			cnt = count[mag_vec[i]];
  			cnt++;
  			count[mag_vec[i]] = cnt;
  		}
  	}

  	map<string, ull>::iterator it = counter.begin();
  	while(it != counter.end())
  	{
  		if (count[it->first] < counter[it->first])
  		{
  			impossible = true;
  		}
  		++it;
  	}

  	printf ("%s\n",impossible?"No":"Yes");

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
