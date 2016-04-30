#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <math.h>

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
#define FORABN(i, a, b) for(i = a; i < b; i++)
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
	ull n,k = 0,i,j,m,l,temp;
	ull page, cnt, prob_num;
	map<ull, set<ull> > chaps;
#if DEBUG 
	srand((unsigned)time(0));
	n = (rand()%10)+1; 
	k = (rand()%10)+1; 
	cout <<n<<" "<<k<<endl;
#else 
	cin >> n>>k;
#endif 

	ull arr[n+1];
	MEM(arr, 0, (n+1), ull);
	page = 0;
	cnt = 1;
	FORAB(i,1, n)
	{
		j = page;
#if DEBUG
		arr[i] = (rand()%10)+1;
		cout <<arr[i]<<" ";
#else
		cin >> arr[i];
#endif
		if (arr[i] > k)
		{
			page += (ull)(ceil(((double)arr[i])/k));
			for (l = j; l < page; l++)
			{
				temp = arr[i];
				prob_num = 1;
				while (temp > 0)
				{
					if (temp < k)
					{
						FORABN(m, prob_num, (prob_num + temp))
						{
							chaps[l+1].insert(m);
						}
						prob_num += temp;
					}
					else
					{
						FORABN(m, prob_num, (prob_num + k) )
						{
							chaps[l+1].insert(m);
						}
						prob_num += k;
					}	
					temp -= k;
					l++;
				}
			}
		}
		else
		{
			page++;

			for (l = j; l < page; l++)
			{
				FORAB(m, 1,  arr[i] )
				{
					chaps[l+1].insert(m);
				}
			}
		}

	}

#if DEBUG
	cout << endl;
#endif
	
	cnt = 0;
	FORAB(i, 1, page)
	{
		set<ull> mySet = chaps[i];

		if(mySet.count(i) != 0)
		{
			cnt++;
		}
	}
	cout << cnt<<endl;
	return 0;
}
