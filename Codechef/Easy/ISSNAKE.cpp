/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/ISSNAKE
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
char s[2][MAXN];

int main() {
	int T;
	scanf("%d", &T);
	assert(T >= 1 && T <= 500);
	while (T--) {
		int n;
		scanf("%d", &n);
		assert(n >= 1 && n <= 500);
		for (int i = 0; i < 2; i++) {
			scanf("%s", s[i]);
			assert(strlen(s[i]) == n);
			for (int j = 0; j < n; j++) {
				assert(s[i][j] == '.' || s[i][j] == '#');
			}
		}
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int same = false;
			if ((s[0][j] == '#' || s[1][j] == '#') && (j + 1 < n && (s[0][j + 1] == '#' || s[1][j + 1] == '#'))) {
				same = true;
			}
			if ((s[0][j] == '#' || s[1][j] == '#') && !same) {
				cnt++;
			}
		}
		//cerr << "cnt " << cnt << endl;
		int ok = true;
		if (cnt > 1) {
			ok = false;
		} else {
			int snakeDecided = false;
			int row = 0;
			for (int j = 0; j < n; j++) {
				if (!snakeDecided) {
					if (s[0][j] == '#' && s[1][j] == '#') {
						continue;
					}
					if (s[0][j] == '#' || s[1][j] == '#') {
						snakeDecided = true;
						row =  s[0][j] == '#' ? 0 : 1;
					}
				} else {
					if (s[0][j] == '.' && s[1][j] == '.') {
						break;
					}
					if (s[row][j] == '#') {
						if (s[row ^ 1][j] == '#') {
							row ^= 1;
						}
					} else {
						if (s[row ^ 1][j] == '#') {
							ok = false;
							break;
						}
					}
				}
			}
		}
		puts(ok ? "yes" : "no");
	}
	return 0;
}
