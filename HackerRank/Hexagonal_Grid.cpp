/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/hexagonal-grid
*/

#include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
string s[2];
bool vis[2][11];

int dfs(int x, int y) {
    if (s[x][y]=='1') return 0;
    vis[x][y] = 1;
    int tot = 1;
    if (x+1<2 && !vis[x+1][y]) tot += dfs(x+1,y);
    if (y+1<n && !vis[x][y+1]) tot += dfs(x,y+1);
    if (x+1<2 && y-1>=0 && !vis[x+1][y-1]) tot += dfs(x+1,y-1);
    if (x-1>=0 && !vis[x-1][y]) tot += dfs(x-1,y);
    if (y-1>=0 && !vis[x][y-1]) tot += dfs(x,y-1);
    if (x-1>=0 && y+1<n && !vis[x-1][y+1]) tot += dfs(x-1,y+1);
    return tot;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        cin>>s[0]>>s[1];
        for (int i=0; i<n; i++) for (int j=0; j<2; j++) vis[j][i] = 0;
        bool bad = 0;
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j]) {
                    int t = dfs(i,j);
                    if (t%2!=0) bad = 1;
                }
            }
        }
        if (bad) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;

}
