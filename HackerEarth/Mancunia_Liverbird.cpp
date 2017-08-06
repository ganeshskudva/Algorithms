/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/mancunian-and-liverbird-go-bar-hopping-2/description/
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ii pair<int,int>
#define ff first
#define ss second
#define ll long long
int left_reach[MAXN][2];
int right_reach[MAXN][2];
int arr[MAXN];
int main(){
    int i,j,n,q,type,idx;
    string s;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
        scanf("%d",&arr[i]);
    
    for(i=1;i<=n;i++)
        if(arr[i-1])    left_reach[i][1] = left_reach[i-1][1] + 1,left_reach[i][0] = 1;
        else            left_reach[i][0] = left_reach[i-1][0] + 1, left_reach[i][1] = 1;
        
    for(i=n;i>=1;i--)
        if(arr[i])      right_reach[i][0] = right_reach[i+1][0] + 1,right_reach[i][1] = 1;
        else            right_reach[i][1] = right_reach[i+1][1] + 1,right_reach[i][0] = 1;
    type = 0;
    scanf("%d",&q);
    while(q--){
        cin>>s;
        if(s[0]=='U')   type ^= 1;
        else            scanf("%d",&idx), printf("%d\n",left_reach[idx][type]+right_reach[idx][type]-1);
    }
    
    return 0;
}
