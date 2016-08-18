#include<bits/stdc++.h>
using namespace std;
#define assn(n,a,b) assert(n>=a && n<=b)
bool check(string s)
{
    int n=s.size();
    for(int i=0; i<=n/2; i++)
	if(s[i]!=s[n-i-1])return false;
    return true;
}
int main()
{
    int t;
    cin >> t;
    assn(t,1,100);
    while(t--)
    {
	string s;
	cin >> s;
	int n=s.size(),flag=0;
	assn(n,1,101);
	for(int i=0; i<n; i++)
	    if(s[i]!='1' && s[i]!='8' && s[i]!='0')flag=1;
	if(flag==1)printf("NO\n");
	else if(check(s))printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}