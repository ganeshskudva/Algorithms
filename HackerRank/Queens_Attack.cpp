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
	ull t = 0,i,j, l, n, val, k, qr, qc, obr, obc, cnt;
	string str;
	map<ull, set<ull> > obst;
	set<ull> temp;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n >> k;
	cin >> qr >> qc;
#endif 

	for (i = 1; i <=k ; i++)
	{
		cin >> obr >> obc;
		temp.clear();
		if (obst.find(obr) == obst.end())
		{
			temp.insert(obc);
			obst[obr] = temp;
		}
		else
		{
			temp = obst[obr];
			temp.insert(obc);
			obst[obr] = temp;
		}
	}


	cnt = 0;
	temp.clear();
/*Row wise calc*/
	for (i = qr+1; i <= n; i++)
	{
		if (obst.find(i) == obst.end())
		{
			cnt++;
		}
		else
		{
//			val = obst[i];
			temp = obst[i];
//			if (val == qc)
			if (temp.count(qc) != 0)
			{
				break;
			}
			else
			{
				cnt++;
			}
		}
	}

	temp.clear();
	for (i = qr - 1; i >= 1; i--)
	{
		if (obst.find(i) == obst.end())
		{
			cnt++;
		}
		else
		{
//			val = obst[i];
			temp = obst[i];
//			if (val == qc)
			if (temp.count(qc) != 0)
			{
				break;
			}
			else
			{
				cnt++;
			}
		}
	}

	temp.clear();
/*Col wise calc*/
	for (i = qc + 1; i <= n; i++)
	{
		if (obst.find(qr) == obst.end())
		{
			cnt++;
		}
		else
		{
//			val = obst[qr];
			temp = obst[qr];
//			if (val == i)
			if (temp.count(i) != 0)
			{
				break;
			}
			else
			{
				cnt++;
			}
		}
	}

	temp.clear();
	for (i = qc - 1; i >= 1; i--)
	{
		if (obst.find(qr) == obst.end())
		{
			cnt++;
		}
		else
		{
//			val = obst[qr];
			temp = obst[qr];
//			if (val == i)
			if (temp.count(i) != 0)
			{
				break;
			}
			else
			{
				cnt++;
			}
		}
	}

/*Diagonal wise  calc*/
	bool leftBlock = false;
	bool rightBlock = false;
	temp.clear();
	for (i = qr - 1, j = qc + 1, l = qc - 1; i >= 1; i--, j++, l--)
	{
		if ((j >= 1) && (j <= n) && !rightBlock)
		{
			if (obst.find(i) == obst.end())
			{
				cnt++;
			}
			else
			{
//				val = obst[i];
				temp = obst[i];
//				if (val == j)
				if (temp.count(j) != 0)
				{
					rightBlock = true;
				}
				else
				{
					cnt++;
				}
			}
		}

		if ((l >= 1) && (l <= n) && !leftBlock)
		{
			if (obst.find(i) == obst.end())
			{
				cnt++;
			}
			else
			{
//				val = obst[i];
				temp = obst[i];
//				if (val == l)
				if (temp.count(l) != 0)
				{
					leftBlock = true;
				}
				else
				{
					cnt++;
				}
			}
		}
	}

	leftBlock = false;
	rightBlock = false;
	temp.clear();
	for (i = qr + 1, j = qc + 1, l = qc - 1; i <= n; i++, j++, l--)
	{
		if ((j >= 1) && (j <= n) && !rightBlock)
		{
			if (obst.find(i) == obst.end())
			{
				cnt++;
			}
			else
			{
//				val = obst[i];
				temp = obst[i];
//				if (val == j)
				if (temp.count(j) != 0)
				{
					rightBlock = true;
				}
				else
				{
					cnt++;
				}
			}
		}

		if ((l >= 1) && (l <= n) && !leftBlock)
		{
			if (obst.find(i) == obst.end())
			{
				cnt++;
			}
			else
			{
//				val = obst[i];
				temp = obst[i];
//				if (val == l)
				if (temp.count(l) != 0)
				{
					leftBlock = true;
				}
				else
				{
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

#if CLOCK
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#endif
	return 0;
}
