/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
*/


#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long unsigned LLU;
#define MOD 1000000007
LLU hash(VI freq)
{
    LLU t=1,ret=0;
    for(int i=0; i<26; i++)
    {
        ret += t*freq[i];
        t=t*(LLU)1000003;
    }
    return ret;
}
int main()
{
    int t;
    sd(t);
    while(t--)
    {
        string s;
        map < LLU , int > mmap;
        int n,ans=0;
        cin >> s;
        n=s.length();
        for(int i=0; i<n; i++)
        {
            VI freq;
            freq.resize(26);
            fill(freq.begin(), freq.end(), 0);
            for(int j=i; j<n; j++)
            {
                freq[s[j]-'a']++;
                mmap[hash(freq)]++;
            }
        }
        for(map<LLU,int>::iterator it=mmap.begin(); it!=mmap.end(); it++)
            ans += (it->S*(it->S-1))/2;
        cout << ans << endl;
    }
    return 0;
}
