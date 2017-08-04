/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/count-friends/description/
*/

#include <bits/stdc++.h>
using namespace std;
struct subset
{
	int parent,sz;
};
vector< subset> subsets;
int find( int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
 
    return subsets[i].parent;
}
 
 
void uniona(int x, int y){
	if( x == y)
	return ;
    int xroot = find( x);
    int yroot = find( y);
    if (subsets[xroot].sz < subsets[yroot].sz){
        subsets[xroot].parent = yroot;
        subsets[yroot].sz += subsets[xroot].sz;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].sz += subsets[yroot].sz;
    }
}
int main()
{
	int i,j,n,m;
	cin>>n>>m;
	subsets.clear();
	subsets.resize(n);
	
	for(i=0;i<n;i++){
		subsets[i].parent=i;
		subsets[i].sz=1;
	}
	for(i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		uniona ( find(--x), find(--y));
	}
	for(i=0;i<n;i++){
		cout<<subsets[find(i)].sz-1<<" ";
	}
    return 0;
}
