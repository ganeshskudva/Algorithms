/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/LEVY
*/

#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cmath>
#include<cstring>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll read_int(ll mn, ll mx, char next){
  int c, fg = 1, res = 0;
  c=getchar();
  if(c=='-') fg = -1, c = getchar();
  assert('0'<=c && c<='9');
  res = c - '0';
  for(;;){
    c = getchar();
    if(c==next) break;
    assert(res!=0);
    assert('0'<=c && c<='9');
    res = res * 10 + (c - '0');
  }
  res *= fg;
  assert(mn<=res && res<=mx);
  return res;
}

int is_prime(int n){
  int i;
  if(n <= 1) return 0;
  if(n <= 3) return 1;
  for(i=2;i*i<=n;i++) if(n%i==0) return 0;
  return 1;
}

int main(){
  int T, N;
  int i, j, k;
  int is_prime[10001];
  int res[10001]; // res[i] = the answer for input i

  // sieve
  rep(i,10001) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  REP(i,2,10001) if(is_prime[i]){
    for(j=i*i;j<=10000;j+=i) is_prime[j] = 0;
  }

  // bruteforce
  rep(i,10001) res[i] = 0;
  rep(i,10001) if(is_prime[i]){
    for(j=1;i+2*j<=10000;j++) if(is_prime[j]) res[i+2*j]++;
  }

  T = read_int(1, 100000, '\n');
  while(T--){
    N = read_int(1, 10000, '\n');
    printf("%d\n",res[N]);
  }

  assert( scanf("%*c")==EOF );
  return 0;
}
