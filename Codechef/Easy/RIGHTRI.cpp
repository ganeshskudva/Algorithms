#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdio>

using namespace std;


#define maxn 20
#define maxt 100000


typedef pair<int,int> pi;

inline int sqr(int x) {return x*x;}

// The squared euclidian distance
int dist(pi A,pi B)
{
   return sqr(A.first-B.first)+sqr(A.second-B.second);
}

int area(pi A,pi B,pi C)
{
   return A.first*(B.second-C.second)+B.first*(C.second-A.second)+C.first*(A.second-B.second);
}

int check(pi A,pi B,pi C)
{
   int a=dist(A,B),b=dist(B,C),c=dist(C,A);
   if(area(A,B,C)==0) return -1;
   if(a+b==c || c+a==b || b+c==a) return 1;
   return 0;
}

void passert(pi A)
{
   assert(A.first>=0 && A.first<=maxn);
   assert(A.second>=0 && A.second<=maxn);
}

int main()
{
   int T,ans=0;

   scanf("%d",&T);
   assert(T>=1 && T<=100000);

   while(T--)
   {
      pi A,B,C;
      scanf("%d%d",&A.first,&A.second);
      scanf("%d%d",&B.first,&B.second);
      scanf("%d%d",&C.first,&C.second);
      passert(A);
      passert(B);
      passert(C);

      assert(check(A,B,C)!=-1);
      if(check(A,B,C)) ans++;
   }

   printf("%d\n",ans);

	return 0;
}


