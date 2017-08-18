/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/TASHIFT
*/
 
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
 
 
 
char A[2000005],B[2000005];
int p[2000005];
int best,ans;
 
void KMP(int x,int y,char *X,char *Y)
{
   int i,k=0,q;
 
   p[1]=0;
 
   for(q=2;q<=y;q++)
   {
      while(k>0 && Y[k]!=Y[q-1]) k=p[k];
      if(Y[k]==Y[q-1]) ++k;
      p[q]=k;
   }
 
 
   for(q=i=0;i<x;i++)
   {
      while(q>0 && Y[q]!=X[i])
         q=p[q];
      if(Y[q]==X[i])
         q++;
 
      if(q>best)
      {
         best=q;
         ans=i-q+1;
      }
     //printf("%d %d %d\n",i,q,i-q+1);
   }
}
 
int main()
{
	int m,i,j,k,tests,cs=0,t=0,n;
 
   scanf("%d%s%s",&n,A,B);
 
   int a=strlen(A),b=strlen(B);
 
   assert(n>=1 && n<=1000000 && a==b && n==a);
 
   for(i=0;i<n;i++) B[b++]=B[i];
   B[b]='\0';
   //printf("%s %s\n",B,A);
 
   best=ans=0;
   KMP(b,a,B,A);
   printf("%d\n",ans);
 
 
	return 0;
}
