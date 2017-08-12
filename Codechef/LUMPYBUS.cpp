/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/LUMPYBUS
*/

#include "bits/stdc++.h"
using namespace std;
 
const int N = 100000 + 50;
 
int t, n;
long long arr[N];
long long odd[N], even[N], odd_sum[N], even_sum[N];
long long p, q;
 
inline int solve(int sz, long long amt){
    int l = 1, r = sz, res = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(amt >= even_sum[mid]){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}
 
int main(){
    cin >> t;
    while(t--){
        cin >> n >> p >> q;
        int odd_idx = 0, even_idx = 0;
        vector < int > o, e;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            if(arr[i] & 1) o.push_back(arr[i]);
            else e.push_back(arr[i]);
        }
        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        for(int i = 0; i < (int) o.size(); i++){
            odd[i + 1] = o[i];
            odd_sum[i + 1] = odd_sum[i] + o[i];
        }
        for(int i = 0; i < (int) e.size(); i++){
            even[i + 1] = e[i];
            even_sum[i + 1] = even_sum[i] + e[i];
        }
        odd_idx = (int) o.size(), even_idx = (int) e.size();
        int ans = 0;
        for(int i = 0; i <= odd_idx; i++){
            if(p < i) break; // Atleast need (i) one rupee coins.
            if(p + 2 * q >= odd_sum[i])
                 ans = max(ans, i + solve(even_idx, p + 2 * q - odd_sum[i]));            
        }
        cout << ans << '\n';
    }
}
