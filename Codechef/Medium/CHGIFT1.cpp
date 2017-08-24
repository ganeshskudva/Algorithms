#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int t, n, num[10];
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", num+i);
        ll mn, mx;
        mn = mx = num[0];
        for(int i = 1; i < n; ++i) {
            ll new_mn = mn + num[i], new_mx = mn + num[i];

            new_mn = min(new_mn, mn + num[i]);
            new_mn = min(new_mn, mx + num[i]);
            new_mn = min(new_mn, mn - num[i]);
            new_mn = min(new_mn, mx - num[i]);
            new_mn = min(new_mn, mn * num[i]);
            new_mn = min(new_mn, mx * num[i]);

            new_mx = max(new_mx, mn + num[i]);
            new_mx = max(new_mx, mx + num[i]);
            new_mx = max(new_mx, mn - num[i]);
            new_mx = max(new_mx, mx - num[i]);
            new_mx = max(new_mx, mn * num[i]);
            new_mx = max(new_mx, mx * num[i]);

            mx = new_mx;
            mn = new_mn;
        }

        printf("%lld\n", mn);
    }
	return 0;
}
