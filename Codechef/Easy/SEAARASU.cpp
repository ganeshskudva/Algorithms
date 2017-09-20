/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/SEAARASU
*/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[111111];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (;t;t--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			while (ans && x) {
				if (ans > x) {
					ans %= x;
				} else {
					x %= ans;
				}
			}
			ans += x;
		}
		long long A = ans;
		cout << A * n << endl;
	}
	return 0;
}
