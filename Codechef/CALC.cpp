/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/JULY17/problems/CALC
*/


#include<bits/stdc++.h>
using namespace std;
const int MX = (1<<17);
long long n , b;
long long F(long long x){
    if(x > n) return 0;
    return x * (n - x * b);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>b;
        int sol = n/(2*b);
        cout<<max(F(sol) , F(sol+1))<<endl;
    }
}
