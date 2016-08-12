/*
* Author: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/milly-and-equal-array/description/
*/

#include <stdio.h>
#include <assert.h>
#define maxm 1e9
int main() 
{
	int t;
	scanf("%d", &t);
	assert(1 <= t && t <= 5);
	while(t--) {
		int n, x, y, z;
		scanf("%d%d%d%d", &n, &x, &y, &z);
		assert(2 <= n && n <= 100000);
		bool flag = 0;
		int b;
		for(int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			assert(1 <= a && a <= maxm);
			while(a % x == 0) a /= x;
			while(a % y == 0) a /= y;
			while(a % z == 0) a /= z;
			if (i > 1 && a != b) {
				flag = 1;
				//break;
			}
			b = a;
		}
		if (flag) printf("She can't\n");
		else printf("She can\n");
	}
	return 0;
}
