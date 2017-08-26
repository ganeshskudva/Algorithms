/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/PHYSICS
*/


#include <bits/stdc++.h>
using namespace std;

#define mx 100005
int h[mx];
int n,f;

bool power_of(int a,int f){
    while(a%f==0) a/=f;
    if(a==1) return true;
    else return false;
}

void solve_small(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(h[i] % h[j] == 0){
                if(power_of(h[i]/h[j],f)) ans++;
            }
            else if(h[j] % h[i] == 0){
                if(power_of(h[j]/h[i],f)) ans++;
            }
        }
    }
    printf("%d\n",ans);
}

map<int,int> mp;
void solve_large(){
    mp.clear();
    for(int i=0;i<n;i++){
        int base=h[i];
        while(base%f==0){
            base/=f;
        }
        mp[base]++;
    }

    int ans=0;
    for(map<int,int>::iterator itr=mp.begin();itr!=mp.end();itr++){
        int e=itr->second;
        ans+=(e*(e-1))/2;
    }
    printf("%d\n",ans);

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&f);
        for(int i=0;i<n;i++) scanf("%d",&h[i]);
        solve_large();
    }
}
