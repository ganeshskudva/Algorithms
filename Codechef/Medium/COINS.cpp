#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

map<ull,ull> mymap;

ull max(ull n,ull k)
{
     return (n > k)?n:k;
}

ull f(long long n)
{
         if(n==0)
         return 0;
         
         ull a=mymap[n];
     
         if(a==0)
         {
                 a=max(n,f(n/2)+f(n/3)+f(n/4));
                 mymap[n]=a;
         }
     
         return a;
     
}

int main()
{
    ull n;
    
    mymap.clear();
    
    while (scanf("%llu",&n)!=EOF)
    {
        ull b=f(n);
              
        cout<<b<<endl;
              
    }
    
    return 0;
    
}