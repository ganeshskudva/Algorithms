/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/ANUBTG
*/

#include <cstdio>
#include <cassert>
#include <algorithm>
 
#define TLIMIT 1000
#define NLIMIT 1000
#define ALIMIT 1000
 
int a[NLIMIT];
int main() {
	int t;
	scanf("%d", &t);
	assert(1 <= t && t <= TLIMIT);
 
	while(t--) {
		int n;
		scanf("%d", &n);
		assert(1 <= n && n <= NLIMIT);
 
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			assert(1 <= a[i] && a[i] <= ALIMIT);
		}
 
		std::sort(a, a+n);
 
		int ans = 0;
		for(int i=n-1; i >= 0; i -= 4) {
			ans += a[i];
			if(i) ans += a[i-1];
		}
 
		printf("%d\n", ans);
	}
} 
