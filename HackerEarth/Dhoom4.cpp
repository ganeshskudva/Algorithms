/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/description/
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD                     1000000007
#define pb(x)                   push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF                      first
#define SS                      second
#define s(n)                    scanf("%d",&n)
#define sl(n)                   scanf("%lld",&n)
#define sf(n)                   scanf("%lf",&n)
#define ss(n)                   scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF                     (int)1e9
#define LINF                    (long long)1e18
#define EPS                     1e-9
#define maX(a,b)                ((a)>(b)?(a):(b))
#define miN(a,b)                ((a)<(b)?(a):(b))
#define abS(x)                  ((x)<0?-(x):(x))
typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;
int key, lck;
int n;
int a[1003];
int val[100005];
void precompute() {
	
}
void read() {
	s(key), s(lck);
	s(n);
	assert(n <= 1000);
	for (int i = 0; i < n; ++i) {
		s(a[i]);	
		assert(a[i] <= 100000);
	}
}
void preprocess() {
	memset(val, -1, sizeof val);
	val[key] = 0;
}
void solve() {
	queue<int> q;
	q.push(key);
	while(!q.empty()) {
		int f = q.front();		
		q.pop();
		for (int i = 0; i < n; ++i) {
			int nw = (1LL * f * a[i]) % 100000;
			if(val[nw] == -1) {
				val[nw] = 1 + val[f];
				q.push(nw);
			}
		}
	}
	printf("%d\n", val[lck]);
}
int main() {
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}
