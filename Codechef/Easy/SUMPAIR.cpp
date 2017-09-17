/*
* AUTHOR: Ganesh S Kudva
* http://www.spoj.com/problems/ARMY/
*/

#include<bits/stdc++.h>

using namespace std;

#define N 1123456

long long int dp[N];
int a[N];

int main(){
    int t, sum_n = 0;
    cin>>t;
    assert(1 <= t && t <= 100000);
    while(t--){
        int n, d;
        cin>>n>>d;
        sum_n += n;
        assert(1 <= n && n <= 100000);
        assert(1 <= d && d <= 100000);
        dp[0] = 0;
        a[0] = -123456;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
            assert(1 <= a[i] && a[i] <= 100000);
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
            assert(1 <= a[i] && a[i] <= 100000);
            dp[i] = dp[i - 1];
            if(a[i] - a[i - 1] < d){
                dp[i] = max(dp[i], dp[i - 2] + a[i] + a[i - 1]);
            }
        }
        cout<<dp[n]<<'\n';
    }
    assert(1 <= sum_n && sum_n <= 500000);
    return 0;
}	
