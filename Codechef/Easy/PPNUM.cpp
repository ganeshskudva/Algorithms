/*
* Author: Ganesh Kudva
* https://www.codechef.com/problems/PPNUM
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<ctime>
#include<cassert>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MP make_pair
#define pb push_back



#define M 1000000007
#define maxt 1000

typedef long long  LL;


LL maxn=1;


int main()
{
   int i,j,k,T,p,q,a;
   for(i=0;i<9;i++) maxn*=10;
   cin>>T;
   assert(T>=1 && T<=1000);
   while(T--)
   {
      LL L,R;
      cin>>L>>R;

      assert(L>=1 && R>=L && R<=maxn);

      LL p=1;
      LL ans=0;

      for(i=1;i<=10;p*=10,i++)
      {
         LL q=p*10-1;

         LL x=MAX(p,L);
         LL y=MIN(q,R);

         if(x>y) continue;

         x%=M;
         y%=M;
         LL r= ( y*(y+1)/2 - x*(x-1)/2)%M;
         r=(r*i)%M;

         ans=(ans+r)%M;
      }

      if(ans<0) ans+=M;
      cout<<ans<<endl;
   }

	return 0;
}


