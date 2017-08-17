/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/CSS2
*/

#include <bits/stdc++.h>
using namespace std;

int Value[1001][1001],Priority[1001][1001];

void solve_20(){
    int n,m;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            Priority[i][j]=-1;
        }
    }
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        int id,attr,val,priority;
        scanf("%d %d %d %d",&id,&attr,&val,&priority);

        if(Priority[id][attr] <= priority){
            Value[id][attr]=val;
            Priority[id][attr]=priority;
        }
    }

    for(int i=0;i<m;i++){
        int tid,tattr;
        scanf("%d %d",&tid,&tattr);

        printf("%d\n",Value[tid][tattr]);

    }
}


int id[1001],attr[1001],val[1001],priority[1001];

void solve_30(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&id[i],&attr[i],&val[i],&priority[i]);
    }

    for(int i=0;i<m;i++){
        int tid,tattr;
        scanf("%d %d",&tid,&tattr);

        int old_pr=-1,tval;

        for(int j=0;j<n;j++){
            if(id[j]==tid and attr[j]==tattr){
                if(priority[j]>=old_pr){
                    old_pr=priority[j];
                    tval=val[j];
                }
            }
        }
        assert(old_pr>=1);
        printf("%d\n",tval);

    }
}


typedef pair<int,int> pii;
map<int,pii> prop[1000001];

void solve_50(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        int id,attr,val,priority;
        scanf("%d %d %d %d",&id,&attr,&val,&priority);

        if(prop[id].find(attr) == prop[id].end()){
            prop[id][attr]=pii(val,priority);
        }
        else{
            pii curr=prop[id][attr];
            if(curr.second <= priority){
                prop[id][attr]=pii(val,priority);
            }
        }
    }
    for(int i=0;i<m;i++){
        int id,attr;
        scanf("%d %d",&id,&attr);
        assert(prop[id].find(attr) != prop[id].end());
        printf("%d\n",prop[id][attr].first);
    }
}

int main(){
    solve_50();
}
