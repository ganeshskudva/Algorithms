#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int T;
  char R[1111], S[1111];
  
  int i,j,k;
  int lenR, lenS;
  int cntR[26], cntS[26]; /* cntR[i] denotes the number of the i-th alphabetical letter in the R */
  int find;

  assert( scanf("%d",&T)==1 );
  assert( 1<=T && T<=100 );
  while(T--){
    assert( scanf("%s%s",R,S)==2 );
    lenR = strlen(R);
    lenS = strlen(S);

    assert(1<=lenR&&lenR<=1000 && 1<=lenS&&lenS<=1000);
    rep(i,lenR) assert('a'<=R[i]&&R[i]<='z');
    rep(i,lenS) assert('a'<=S[i]&&S[i]<='z');

    rep(i,26) cntR[i] = cntS[i] = 0;
    rep(i,lenR) cntR[R[i]-'a']++;
    rep(i,lenS) cntS[S[i]-'a']++;

    find = 0;
    rep(i,26) if(cntR[i]!=cntS[i]) find = 1; /* different frequencies in two recipes */
    rep(i,26) if((cntR[i] && !cntS[i]) || (!cntR[i] && cntS[i])) find = 0; /* Chef may consider "not GRANAMA" */

    if(find) puts("NO"); else puts("YES");
  }

  return 0;
}
