#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000005;

bool wal[maxn];
int n,s,t,g,seed,p,b[maxn],a[maxn];

int main()
{
	scanf("%d%d%d", &n, &s, &t);
	scanf("%d%d%d%d",&a[0], &g, &seed, &p);
	for(int i = 1;i < n;i ++) a[i] = (a[i - 1] * 1ll * g + seed) % p;
	for(int i = s;i < n;i ++) b[i - s] = a[i];
	for(int i = 0;i < s;i ++) b[i + n - s] = a[i];
	t = (t - s + n) % n;
	int l = 0,r = 0;
	for(int i = 0;i <= n;i ++)
	{
		if (t <= r || t >= n + l) {printf("%d\n", i);return 0;}
		int pl = l,pr = r;
		for(int j = pl;j < 0;j ++)
			if (wal[j + n]) break; else
				r = max(r,j + b[j + n]),l = min(l,j - b[j + n]),wal[j + n] = 1;
		for(int j = pr;j >= 0;j --)
			if (wal[j]) break; else
				r = max(r,j + b[j]),l = min(l,j - b[j]),wal[j] = 1;
	}
	printf("-1\n");
	return 0;
}