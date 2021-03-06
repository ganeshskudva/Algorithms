/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/CROWD
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

//copy both the functions
//dimension of matrix: 3
// matrix_mul(a,b,c): multiplies matrix a with b and puts the result in c
// matrix_expo(a,4,c): calculates a^4 and puts in c

LL mypow(LL a, LL n)
{
    LL r = 1;
    for(;n;n>>=1)
    {
        if(n&1) r = (r*a)%mod;
        a = (a*a)%mod;
    }
    return r;
}

void matrix_mul(LL a[3][3],LL b[3][3],LL c[3][3])
{
    REP(i,3)
    REP(j,3)
    {
        c[i][j]=0;
        REP(k,3)
        {
            LL temp=a[i][k]*b[k][j];
            if(temp>=mod)
                temp%=mod;
            c[i][j]+=temp;
            if(c[i][j]>=mod)
                c[i][j]%=mod;
        }
    }
}

LL id[3][3]={{1,0,0},{0,1,0},{0,0,1}};

void matrix_expo(LL a[3][3], LL n,LL h[3][3])
{
    if(n==1)
    {
        REP(i,3)
        REP(j,3)
        h[i][j]=a[i][j];
        return;
    }
    else if(n==0)
    {
        REP(i,3)
        REP(j,3)
        h[i][j]=id[i][j];
        return;
    }
    
    LL c[3][3];
    LL x[3][3];
    
    matrix_expo(a,n/2,x);
    matrix_mul(x,x,c);
    
    if(n%2==1)
    {
        matrix_mul(a, c, h);
        return;
    }
    else
    {
        REP(i,3)
        REP(j,3)
        h[i][j]=c[i][j];
        return;
    }
}


int main(){
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL a[3][3]={{1,1,1},{1,0,0},{0,1,0}};
        LL b[3][3];
        
        LL n;
        scanf("%lld",&n);
        if(n<=3)
        {
            if(n==1)
                printf("0\n");
            else if(n==2)
                printf("0\n");
            else
                printf("1\n");
            
        }
        else
        {
            matrix_expo(a,n-3,b);
            LL ans = 7*b[0][0] + 4*b[0][1] + 2*b[0][2];
            if(ans>=mod)
                ans%=mod;
            LL final=mypow(2LL,n);
            final=final-ans;
            while(final<0)
                final+=mod;
            printf("%lld\n",final);
        }
        
    }
    return 0;
}

