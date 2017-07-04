/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/toll-cost-digits
*/

#include <bits/stdc++.h>
using namespace std;

static const long long bs = 1000000007;
static const int INF = 0x3f3f3f3f; 
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;

#define REP(i, n) for (int i=0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define PI 3.14159265
void addmod(ll &a, ll b){a = (a + b); if (a >= bs) a -= bs;}
void mulmod(ll &a, ll b){a = (a * b) % bs;}

struct cmp {
  bool operator()(int &a, int &b) { return a < b; }
};

vector<vector<pii>> G(1e5+10);
vector<vector<int>> memo(10, vector<int>(1e5+10, -1));

vector<int> parent(1e5+10);
vector<int> parent_rank(1e5+10, 1);

int find_parent(int n) {
  if (parent[n] != n) parent[n] = find_parent(parent[n]);
  return parent[n];
}

void merge_nodes(int a, int b) {
  int parentA = find_parent(a);
  int parentB = find_parent(b);

  if (parentA == parentB) return;

  if (parent_rank[parentA] > parent_rank[parentB]) {
    parent[parentB] = parentA;
    parent_rank[parentA] += parent_rank[parentB];
  } else {
    parent[parentA] = parentB;
    parent_rank[parentB] += parent_rank[parentA];
  }
}

void go(int x) {
  stack<pii> s;

  int p = find_parent(x);

  s.push({0, p});


  while (s.size()) {

    auto next = s.top(); s.pop();
    auto cost = next.first;
    auto y = next.second;

    if (memo[cost][y] == -1) {
      memo[cost][y] = p;

      for (auto &f : G[y]) {
        int dd = (cost + f.first) % 10;
        s.push({dd,  f.second});
      }

    } else {
      merge_nodes(memo[cost][y], p);
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, e; cin >> n >> e;

  REP(i, 1e5+6) {
    parent[i] = i;
  }

  REP(i, e) {
    int x, y, r; cin >> x >> y >> r;
    G[x].pb({r, y});
    G[y].pb({1000-r, x});
  }

  vector<ll> ans(10);

  for (int x = 1; x <= n; x++) {
    go(x);
  }

  for (int i = 1; i <= n; i++) {

    for (int d = 0; d <= 9; d++) {

      if (memo[d][i] == -1) continue;

      int p = find_parent(memo[d][i]);
      ll sz = parent_rank[p];


      ans[d] += sz;

      ll owner = find_parent(i);
      if (owner == p) ans[d]--;
    }
  }

  for (int i = 0; i <= 9; i++) cout << ans[i] <<endl;

  return 0;
}
