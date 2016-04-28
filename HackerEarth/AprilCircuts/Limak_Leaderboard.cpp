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

struct comparator {
 bool operator()(int i, int j) {
 return i > j;
 }
};

int main()
{
	ull q,n = 0, idx, points, sum,i, prev;
	std::map <ull, ull> board;
	priority_queue<int, std::vector<int> > maxHeap;

#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> n>>q;
#endif 

	vector<ull> leaderboard ((n+1), 0);

	while (q--)
	{
		cin >> idx;
		cin >> points;

		board[idx] += points;

		std::map<ull, ull>::iterator map_it = board.begin();
		for (i = 0; map_it != board.end(); map_it++, i++)
		{
//			leaderboard[i] = map_it->second;
			maxHeap.push(map_it->second);
		}
//		leaderboard[idx] = board[idx];
		sort(leaderboard.begin(), leaderboard.end(), std::greater<ull>());
		sum = 0;
/*
		for (i = 0; i < n; i++)
		{
			if (leaderboard[i] == leaderboard[i - 1])
			{
				sum += ((i) * leaderboard[i]);
			}
			else
			{
				sum += ((i+1) * leaderboard[i]);
			}
		}
*/
		i = 1;
		prev = 0;
		while (!maxHeap.empty())
		{
			if (maxHeap.top() != prev)
			{
				prev = maxHeap.top();
				maxHeap.pop();
				sum += (i * prev);

			}
			else
			{
				sum += ((i - 1) * prev);
				maxHeap.pop();
			}
			i++;
		}
		cout << sum << endl;
	}

	return 0;
}
