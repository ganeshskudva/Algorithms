/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/LEMOUSE
*/

/*
Dynamic programming: F[i][j][pr] is the minimal number of mices that scares the elephant when the elephant move from (1, 1) to (i, j).
Pr is used to store the last cell that the elephant enterd before move to (i, j).
*/
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define DOWN(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

using namespace std;

int cx[] = {1, 0};
int cy[] = {0, 1};

int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0};

int m, n;
string a[122];
int f[122][122][2];

bool inside(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int call (vector < pair <int, int> > cell, int x, int y) {
    int cnt = 0;

    FOR (dir, 0, 4) {
        cnt++;
        int xx = x + dx[dir];
        int yy = y + dy[dir];

        if (!inside(xx, yy)) {
            cnt--;
            continue;
        }

        if (a[xx][yy] == '0') {
            cnt--;
            continue;
        }

        FOREACH(it, cell) {
            int a = (*it).first;
            int b = (*it).second;

            if ((abs(a - xx) + abs(b - yy)) <= 1) {
                cnt--;
                break;
            }
        }
    }

    return cnt;
}

int main() {
    int ntest;
    cin >> ntest;

    while (ntest--) {
        cin >> n >> m;
        FOR (i, 0, n - 1)
            cin >> a[i];

        FOR (x, 0, n - 1)
        FOR (y, 0, m - 1)
            f[x][y][0] = f[x][y][1] = m * n;

        f[0][0][0] = f[0][0][1] = (a[0][0] == '1') + (a[0][1] == '1') + (a[1][0] == '1');

        FOR (x, 0, n - 1)
        FOR (y, 0, m - 1)
        FOR (pr, 0, 1)
        FOR (prpr, 0, 1)
            if (x + y) {
                //pr is the last move that make elephant enter the cell(x, y);
                //prpr is the move before that move

                int px = x - cx[pr], py = y - cy[pr];

                if (!inside(px, py)) continue;

                vector < pair <int, int> > cell;
                cell.push_back(make_pair(px, py));

                int ppx = px - cx[prpr], ppy = py - cy[prpr];

                if (inside(ppx, ppy))
                    cell.push_back(make_pair(ppx, ppy));

                f[x][y][pr] = min(f[x][y][pr], f[px][py][prpr] + call(cell, x, y));
            }

        cout << min(f[n - 1][m - 1][0], f[n - 1][m - 1][1]) << endl;
    }

    return 0;
}
