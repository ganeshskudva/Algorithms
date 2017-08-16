/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/AND
*/

#include <stdio.h>

int n,i,j,ai,kk[30]; // kk[i] equals to amount of numbers where the i-th bit is not a zero
long long ans=0; // answer to the problem

int main(){
	scanf("%d",&n); // size of the sequence
	for(i=0;i<n;i++){
		scanf("%d",&ai);
		for(j=0;j<30;j++)if(ai&(1<<j))++kk[j]; // ai & (1<<j) isn't equal to zero only in case the j-th bit in ai is not a zero
	}
	for(j=0;j<30;j++)ans+=1LL*kk[j]*(1LL*kk[j]-1LL)*(1LL<<j); // calculate the answer according to the provided formula
	printf("%lld\n",ans/2LL);
	return 0;
}
