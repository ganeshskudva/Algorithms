/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/motu-and-patlu-1-ab612ad8/description/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long mod=1000000007;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll i=0,j=n-1,sum1=0,sum2=0;
        if(n==1)
        {
            cout<<"1 0"<<endl;
            cout<<"Motu"<<endl;
        }
        else
        {
            int flag=0;
            sum1=0;sum2=0;
            while(i<=j)
            {
                if(sum1<=(2*sum2))
                {
                    while((sum1<=2*sum2)&&i<=j)
                    {
                        sum1+=a[i];
                        i++;
                    }
                }
                else
                if(sum1>sum2)
                {
                    while((sum1>2*sum2)&&j>=i)
                    {
                        sum2+=a[j];
                        j--;
                    }
                }
            }
            ll p,q;
            p=i;q=n-j-1;
            cout<<p<<" "<<q<<endl;
            if(p>q)
            cout<<"Motu"<<endl;
            else
            if(q>p)
            cout<<"Patlu"<<endl;
            else
            cout<<"Tie"<<endl;
        }
    }
    return 0;
}
