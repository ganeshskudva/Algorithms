/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/DISHOWN
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

//#define assert(x) x

const int maxn = 1000000;

int father[maxn], s[maxn];

int find(int x)
{
	int y = x;
	while (x != father[x]) {
		x = father[x];
	}
	for (;y != x;) {
		int t = father[y];
		father[y] = x;
		y = t;
	}
	return x;
}

int main()
{
	int T;
	for (assert(scanf("%d", &T) == 1 && 1 <= T && T <= 25); T --;) {
		int n, q;
		assert(scanf("%d", &n) == 1);
		assert(1 <= n && n <= maxn);
		for (int i = 0; i < n; ++ i) {
			assert(scanf("%d", &s[i]) == 1);
			assert(0 <= s[i] && s[i] <= 1000000);
			father[i] = i;
		}
		assert(scanf("%d", &q) == 1);
		assert(1 <= q && q <= maxn);
		for (int i = 0; i < q; ++ i) {
			int op, x, y;
			assert(scanf("%d", &op) == 1);
			assert(op == 0 || op == 1);
			if (op == 0) {
				assert(scanf("%d%d", &x, &y) == 2);
				assert(1 <= x && x <= n && 1 <= y && y <= n);
				-- x;
				-- y;
				int fx = find(x), fy = find(y);
				if (fx == fy) {
					puts("Invalid query!");
				} else {
					if (s[fx] > s[fy]) {
						father[fy] = fx;
					} else if (s[fx] < s[fy]){
						father[fx] = fy;
					}
				}
			} else {
				assert(scanf("%d", &x) == 1);
				assert(1 <= x && x <= n);
				printf("%d\n", find(x - 1) + 1);
			}
		}
	}
	return 0;
}
