/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/connected-cell-in-a-grid
*/

#include <bits/stdc++.h>
using namespace std;
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } }_;

int arr[11][11];
int m = 0, n = 0;

int ff(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n 
        || arr[i][j] == -1 || arr[i][j] == 1)
        return 0;
    else {
        arr[i][j] = 1;
        return 1 + ff(i+1, j) + ff(i-1, j) + 
               ff(i, j+1) + ff(i, j-1) + 
               ff(i+1, j-1) + ff(i-1, j+1) + 
               ff(i+1, j+1) + ff(i-1, j-1);
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            arr[i][j] = x-1; 
            // -1 = 0s, 0 = unvisited 1s, 1 = visited 1s
        }
    }
    int mx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 0)
                mx = max(mx, ff(i, j));
        }
    }
    cout << mx;
    return 0;
}
