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

// x cats riding on the horses
// x <= min(cats, 2 * dogs).
// 4 * (cats + dogs - x) = legs;

int cats, dogs, legs;

int solveSubtask3() {
	if (legs % 4 != 0) {
		return false;
	}
	long long x = cats + dogs;
	x -= legs / 4;
	//int x = cats + dogs - legs / 4;
	return x >= 0 && x <= min(cats, 2 * dogs);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &cats, &dogs, &legs);
		int ok = solveSubtask3();
		puts(ok ? "yes" : "no");
	}
	return 0;
}
