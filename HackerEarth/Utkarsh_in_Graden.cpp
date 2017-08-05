/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/utkarsh-in-gardens-february-easy/description/
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
bitset<MAXN> g[MAXN], com;
int n;
int main()
{
    scanf("%d", &n);
    assert(1 <= n && n <= 2000);
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		int x;
    		scanf("%d", &x);
    		assert(x == 0 || x == 1);
    		g[i][j] = x;
    	}
    }
    for (int i = 1; i <= n; i++) {
    	assert( g[i][i] == 0 );
    	for (int j = 1; j <= n; j++) {
    		assert(g[i][j] == g[j][i]);
    	}
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = i + 1; j <= n; j++) {
    		long long cnt = 0;
    		cnt = (g[i] & g[j]).count();
    		ans += cnt*(cnt - 1) / 2;
    	}
    }
    cout<<ans/2<<endl;
    return 0;
}
