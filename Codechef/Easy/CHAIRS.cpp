/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/CHAIRS
*/

#include <bits/stdc++.h>
using namespace std;
char sl[1005 * 1005];
void te() {
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	int cnt0 = 0;
	for(int i = 0; i < n; ++i)
		cnt0 += sl[i] == '0';
	int maxConsecutive = 0;
	for(int i = 0; i < n; ++i)
		if(sl[i] == '0' && sl[(i+n-1)%n] == '1') {
			// a new segement with 0's is starting
			int len = 1;
			while(sl[(i+1)%n] == '0') {
				++len;
				++i;
			}
			maxConsecutive = max(maxConsecutive, len);
		}
	printf("%d\n", cnt0 - maxConsecutive);
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) te();
}
