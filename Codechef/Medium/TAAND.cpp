/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/TAAND
*/


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
 
#include<cmath>
#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<cassert>
 
using namespace std;
 
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define MP make_pair
#define pb push_back
#define inf 1000000000
#define   M 1000000007
 
typedef long long  LL;
typedef pair<LL,LL> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int a[3000005],f[3000005];
 
int main()
{
	int m,i,j,k,tests,cs=0,t=0,n;
	scanf("%d",&n);
	assert(n>=2 && n<=300000);
 
	for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        assert(0<=k && k<=1000000000);
        a[i]=k;
    }
 
    int ans=0;
    for(i=30;i>=0;i--)
    {
        int cnt=0;
 
        for(j=0;j<n;j++)
            if(!f[j] && a[j]&(1<<i)) cnt++;
 
        if(cnt<=1) continue;
        ans+=(1<<i);
 
        for(j=0;j<n;j++)
            if(!f[j] && !(a[j]&(1<<i))) f[j]=1;
 
    }
 
    printf("%d\n",ans);
	return 0;
}
