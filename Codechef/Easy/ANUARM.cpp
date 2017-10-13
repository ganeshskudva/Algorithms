/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/ANUARM
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define T_LIMIT 10000
#define N_LIMIT 100000

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);

		int minm = 1111111, maxm = -minm;
		// Find the minimum and maximum.
		while(m--) {
			int x;
			scanf("%d", &x);
			minm = min(x, minm);
			maxm = max(x, maxm);
		}
		// print the answers
		for(int i=0; i<n; i++) {
			printf("%d ", max( abs(i-minm), abs(i-maxm)));
		}
		printf("\n");
	}

}
