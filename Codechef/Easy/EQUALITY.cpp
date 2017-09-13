/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/EQUALITY
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 50500;

int n;
long long sa[MAXN];

void solve() {
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &sa[i]);
		sum += sa[i];
	}
	sum /= n - 1;
	for (int i = 0; i < n; i++) {
		printf("%lld ", sum - sa[i]);
	}
	printf("\n");
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}
