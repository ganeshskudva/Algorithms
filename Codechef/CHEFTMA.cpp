//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>

using namespace std;

const int MAX_N = 1e5;
const int MAX_K = 1e5;
const int MAX_M = 1e5;
const int MAX_A = 1e5;

int lf[MAX_N + 10];

int main() {
    //ios::sync_with_stdio(0);
    int n, k, m;
    scanf("%d %d %d\n", &n, &k, &m);
    assert(1 <= n && n <= MAX_N);
    assert(1 <= k && k <= MAX_K);
    assert(1 <= m && m <= MAX_M);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", lf + i);
        assert(1 <= lf[i] && lf[i] <= MAX_A);
    }
    int b;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b);
        //assert(lf[i] <= b && b <= MAX_A);
        assert(1 <= b && b <= lf[i]);
        lf[i] = lf[i] - b;
    }
    multiset<int> ms;
    for(int i = 0; i < k; ++i) {
        scanf("%d", &b);
        assert(1 <= b && b <= MAX_A);
        ms.insert(b);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &b);
        assert(1 <= b && b <= MAX_A);
        ms.insert(b);
    }
    
    long long ans = 0;
    sort(lf, lf+n); reverse(lf, lf+n);
    for(int i = 0; i < n; ++i) {
        if (ms.empty()) break;
        
        auto x = ms.lower_bound(lf[i]+1);
        if (x == ms.begin()) {
            ans += lf[i];
            continue;
        }
        x--;
        ans += lf[i] - *x;
        ms.erase(x);
    }
    printf("%lld\n", ans);
    return 0;
}
