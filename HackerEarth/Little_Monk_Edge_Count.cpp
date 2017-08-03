/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/little-monk-and-edge-count/
*/

#include <bits/stdc++.h>
using namespace std;
#define NN 101010
int d[NN] = {0}, cnt[NN];
vector<int> gr[NN];
int u[NN], v[NN];
void dfs(int u, int p) {
    d[u] = d[p] + 1;
    cnt[u] = 1;
    for (int i = 0; i < (int) gr[u].size(); ++i) {
        int v = gr[u][i];
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u[i] >> v[i]; --u[i], --v[i];
        gr[u[i]].push_back(v[i]);
        gr[v[i]].push_back(u[i]);
    }
    dfs(0, 0);
    while (q--) {
        int t; cin >> t; --t;
        if (d[u[t]] < d[v[t]]) swap(u[t], v[t]);
        long long x = cnt[u[t]], y = n - x;
        cout << x * y << '\n';
    }   
    return 0;
}
