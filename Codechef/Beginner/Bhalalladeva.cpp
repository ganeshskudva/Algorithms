#include <bits/stdc++.h>
 
//#include <helper.hpp>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
 
int main() {
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;
    vector<int> g(n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &g[i]);
    }
 
    sort(g.begin(), g.end());
    for(int i=1; i<n; ++i) {
        g[i] += g[i-1];
    }
 
    int q;
    cin >> q;
    while(q--) {
        int k;
        scanf("%d", &k);
        int a = n/(k+1);
        if(n % (k+1)) a++;
        printf("%d\n", g[a-1]);
    }
 
    return 0;
}
 