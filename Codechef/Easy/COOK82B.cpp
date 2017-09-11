/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/COOK82B
*/

#include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    #define pb push_back
    #define MOD 1000000007
     
     
    // Fast-Exponentiation
    ll power(ll a, ll b){
        if (b == 0) return 1;
        if (b == 1) return a;
        if (b%2 == 1) return (a*power(a,b-1))%MOD;
        ll x = power(a,b/2)%MOD;
        return (x*x)%MOD;
    }
     
    int main() {
    	
    	ios::sync_with_stdio(false);
    	
        // 	Storing all primes
    	vector<ll> primes;
        primes.pb(2);
        for (int i = 3; i < 31625; i += 2){
            for (int j = 0; j < primes.size(); j++){
                if (i%primes[j] == 0) break;
                if (primes[j]*primes[j] > i){
                    primes.pb(i);
                    break;
                }
            }
        }
    	
        // 	Calculating Prime-Factors
    	int n;
    	cin >> n;
    	ll x;
    	map<ll,ll> mp;
    	for (int i = 0; i < n; i++){
    	    cin >> x;
    	    for (int j = 0; j < primes.size(); j++){
    	        while (x % primes[j] == 0){
    	            x /= primes[j];
    	            mp[primes[j]] ++;
    	        }
    	        if (x == 1) break;
    	    }
    	    if (x > 1) mp[x] ++;
    	}
    	
        // 	Calculating the answer
    	bool justdoit = true;
    	ll ans = 1;
        for (auto it = mp.begin(); it != mp.end(); it++){
            ll a = it->first;
            ll b = it->second;
            if (b%n != 0){ 
                justdoit = false;
            }
            if (b%(n+1) != 0){
                ans *= power(a,n+1-(b%(n+1)));
                ans %= MOD;
            }
        }
        if (justdoit) cout << "justdoit\n";
        else cout << ans << endl;
    }
