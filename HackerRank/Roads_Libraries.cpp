/*
* AUTHOR: Ganesh S Kudva
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

vector<int> adj[100005];
bool visited[100005];
long nodes;

void DFS(int n)
{
    nodes++;
    visited[n] = true;
    for(vector<int>::iterator i = adj[n].begin(); i != adj[n].end() ; i++)
    {
        if(!visited[*i])
            DFS(*i);
    }
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N,M,a,b;
        long X,Y;
        cin >> N >> M >> X >> Y;

        for(int i = 0 ; i < M ; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        long cost=0;

        for(int i = 1 ; i <= N ; i++)
        {
            if(!visited[i])
            {
                nodes = 0;
                DFS(i);
                cost = cost + X;
                if(X > Y)
                    cost = cost + (Y*(nodes-1));
                else
                    cost = cost + (X*(nodes-1));
            }
        }

        cout << cost << endl;
        for(int i=0 ; i<=N ; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
    }

    return 0;
}
