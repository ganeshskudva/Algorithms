/*
* AUTHOR: Ganesh S Kudva
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int ans = 0 , last = '?' , cur = 0;
        for(auto ch : str){
            if(ch == '=') continue;
            if(ch != last){
                ans = max(ans , cur);
                cur = 1;
                last = ch;
            }
            else ++cur;
        }
        ans = max(ans , cur);
        cout<<ans + 1<<endl;
    }
}
