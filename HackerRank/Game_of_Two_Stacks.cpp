/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/game-of-two-stacks
*/

#include <bits/stdc++.h>

typedef long long int ull;

#define MEM(a, b, c, d) memset(a, (b), c * sizeof(d))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

#if 0
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
#endif

#define IN(A, B, C) assert( B <= A && A <= C)

using namespace std;

#define DEBUG 0
#define CLOCK 0

bool isPrime(ull number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

static inline ull is_odd(ull x) { return x & 1; }

int A[100002],B[100002];

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m ,ms;
        scanf("%d%d%d", &n, &m, &ms);
 
        for(int A_i = 0; A_i < n; A_i++){
            scanf("%d",&A[A_i]);
        }
        for(int B_i = 0; B_i < m; B_i++){
           scanf("%d",&B[B_i]);
        }

        long long sum = 0;
        int x = 0, y = 0;

        while (x < n && sum + A[x] <= ms) {
            sum += A[x++];
        }

        int ans = x;

        while (y < m && x >= 0) {
            sum += B[y++];
            while (sum > ms && x > 0) {
                sum -= A[--x];
            }

            if (sum <= ms && ans < x + y) {
                ans = x + y;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
