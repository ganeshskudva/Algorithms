/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/contests/101hack51/challenges/charging-the-batteries
*/


#include <bits/stdc++.h>
 
#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define endl '\n'
 
using namespace std;
 
const ll llinf = 1e18;

int len(pair<int, int> a, pair<int, int> b, int n) {
    if ((a.f == 0 && b.f == n) || (a.f == n && b.f == 0))
        return n + a.s + b.s;
    if ((a.s == 0 && b.s == n) || (a.s == n && b.s == 0))
        return n + a.f + b.f;
    return abs(a.f - b.f) + abs(a.s - b.s);
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    if (k == 1) {
        cout << 0;
        return 0;
    }

    vector<pair<int, int> > a[4];

    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        
        if (x == 0)
            a[0].pb(mp(x, y));
          else if (y == n)
            a[1].pb(mp(x, y));
          else if (x == n)
            a[2].pb(mp(x, y));
          else if (y == 0)
            a[3].pb(mp(x, y));
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(a[2].rbegin(), a[2].rend());
    sort(a[3].rbegin(), a[3].rend());
    vector<pair<int, int> > cur;
    
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < a[j].size(); i++){
            cur.pb(a[j][i]);
        }
    vector<ll> dist, pref, suff;

    for (int i = 0; i < cur.size(); i++){
        int to = i + 1;
        if (to == cur.size())
            to = 0;

        int my_len = len(cur[i], cur[to], n);
        my_len = min(my_len, 4 * n - my_len);
        dist.pb(my_len);
    }

    suff.resize(dist.size());
    suff[suff.size() - 1] = dist.back();

    for (int i = suff.size() - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + dist[i];
    
    pref.resize(dist.size());
    pref[0] = dist[0];

    for (int i = 1; i < dist.size(); i++)
        pref[i] = pref[i - 1] + dist[i];
    k--;

    ll sum = llinf;

    for (int i = 0; i < dist.size(); i++){
        int to = (i + k - 1) % (int)dist.size();
        if (to < i)
            sum = min(sum, suff[i] + pref[to]);
        else
            sum = min(sum, pref[to] - (i == 0 ? 0LL : pref[i - 1]));
    }

    cout << sum;
    return 0;
}
