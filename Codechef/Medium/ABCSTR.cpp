/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/ABCSTR
*/

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
 
int main(){
    string s;
    cin>>s;
    ll ans=0, x=0, y=0, z=0;
    map<pair<ll,ll>,ll> m;
    m[mp(0,0)]=1;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='A')x++;
        else if(s[i]=='B')y++;
        else z++;
        ans+=m[mp(x-y,x-z)];
        m[mp(x-y,x-z)]++;
    }
 
    cout<<ans;
 
    return 0;
}
