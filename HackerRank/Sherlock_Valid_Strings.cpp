/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
*/


#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
using namespace std;
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
int main()
{
    set<int> myset;
    string s;
    cin >> s;
    string ans="NO";
    
    //cnt[i] stores frequency of character i+'a'
    int cnt[26]={},n=s.length();
    
    assn(n,1,100000);
    
    for(int i=0; i<n; i++){
        //increasing frequency
        cnt[s[i]-'a']++;
        assn(s[i]-'a',0,25);
    }
    
    //for i>=0, it means we are removing character i+'a', if possible
    //case i=-1 is for checking if string is already valid
    for(int i=-1; i<26; i++){
    
        //if character i+'a' is not present in string continue
        if(i>=0 and cnt[i]==0)continue;
        
        //reduce frequency
        if(i>=0)cnt[i]--;
        
        //if we insert all positive frequencies into a set, it should contain
        //only 1 element if string is now valid
        set<int> myset;
        
        //insert remaining positive frequencies into set
        for(int j=0; j<26; j++){
            if(cnt[j])myset.insert(cnt[j]);
        }
        
        //if set size is 1, string is now valid
        if(myset.size()==1)ans="YES";
        
        //increase the frequency back again
        if(i>=0)cnt[i]++;
    }
    
    cout << ans << endl;
    return 0;
}
