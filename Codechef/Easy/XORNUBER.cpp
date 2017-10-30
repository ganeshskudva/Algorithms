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
#include<ctime>
using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define MP make_pair
#define pb push_back
#define inf 1000000000
#define   M 1000000007

#define maxn (1<<30)
#define maxt 5000


typedef long long  LL;
typedef pair<LL,LL> pl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;


int n;


int main()
{
	int n,i,j,k,tests=20,cs=0,t=0,a,b;
    srand(time(NULL));
  
    scanf("%d",&tests);
    assert(tests>=1 && tests<=maxt);
    while(tests--)
    {
        scanf("%d",&n);
        assert(n>=1 && n<=maxn);
        if(n==1) // special case
        {
            printf("%d\n",2);
            continue;
        }
        int ans=-1;
        for(i=1;i<=30 && ans<0;i++) // only the cases of the form 2^x-1 have solutions
        {
            int p=(1<<i);

            if( (p ^ (p-1))==n)
                ans=p-1;
        }
        printf("%d\n",ans);

    }



	return 0;
}
