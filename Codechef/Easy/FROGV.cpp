#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

const int maxn = 100000;

struct Frog
{
	int id, x;
}frogs[maxn];

bool byX(const Frog &a, const Frog &b)
{
	return a.x < b.x;
}

int comp[maxn];

int main()
{
	int n, k, p;
	assert(scanf("%d%d%d", &n, &k, &p) == 3 && 1 <= n && n <= maxn && 1 <= p && p <= maxn && 0 <= k && k <= 1000000000);
	for (int i = 0; i < n; ++ i) {
		frogs[i].id = i;
		assert(scanf("%d", &frogs[i].x) == 1 && 0 <= frogs[i].x && frogs[i].x <= 1000000000);
	}
	
	sort(frogs, frogs + n, byX);
	
	for (int i = 0; i < n; ++ i) {
		int j = i + 1;
		comp[frogs[i].id] = i;
		while (j < n && frogs[j].x <= frogs[j - 1].x + k) {
			comp[frogs[j].id] = i;
			++ j;
		}
		i = j - 1;
	}
	
	for (int i = 0; i < p; ++ i) {
		int a, b;
		assert(scanf("%d%d", &a, &b) == 2 && 1 <= a && a <= n && 1 <= b && b <= n);
		-- a;
		-- b;
		printf("%s\n", comp[a] == comp[b] ? "Yes" : "No");
	}
	
	return 0;
}
