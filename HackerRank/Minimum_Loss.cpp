/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/minimum-loss/problem
*/


#include <bits/stdc++.h>
#include<assert.h>

#define pf printf
#define sf scanf

using namespace std;

typedef long long vlong;

const vlong inf = 1000000000000000000LL;


vlong arr[200005];
void solution() {

    set<vlong>st;
    set<vlong>::iterator up;

    int n;
    vlong temp, ans=inf, mx=0;

    sf("%d", &n);
    assert(n>1 && n<=200000);

    for(int i=1; i<=n; i++)
    {
       sf("%lld", &arr[i]);
       assert(arr[i]>0 && arr[i]<=10000000000000000LL);
    }

    st.insert(arr[1]);
    mx = max(mx, arr[1]);
    for(int i=2; i<=n; i++)
    {
        if(mx > arr[i])
        {
            up = st.upper_bound(arr[i]);
            temp = *up - arr[i];
            ans = min(ans, temp);
        }
        st.insert(arr[i]);
        mx = max(mx, arr[i]);
    }

    assert(ans!=inf);

    pf("%lld\n", ans);
}


int main () {

        solution();

    return 0;
}
