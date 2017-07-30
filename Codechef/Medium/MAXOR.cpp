/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/MAXOR
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 17, z = 20, maxk = 1 << z;

int t, n, dp[maxk], exact[maxk];
void solve(){
    cin >> n;
    assert(n <= 1000000);
    for(int i = 0, x; i < n; i++)
	cin >> x, assert(0 <= x && x <= 1000000), dp[x]++;
    long long ans = 0;
    memcpy(exact, dp, sizeof dp);
    for(int j = 0; j < z; j++)
	for(int i = 0; i < maxk; i++)
	    if(i >> j & 1)
		dp[i] += dp[i ^ 1 << j];
    for(int i = 0; i < maxk; i++){
	dp[i] -= exact[i];
	ans += (long long) exact[i] * (2 * dp[i] + exact[i] - 1) / 2;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
	    solve();
	    memset(dp, 0, sizeof dp);
    }
    return 0;
}
