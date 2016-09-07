/*
* AUTHOR: Ganesh S Kudva
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>

typedef long long int ull;

#define MEM(a, b, c, d) memset(a, (b), c * sizeof(d))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

#if 0
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
#endif

#define IN(A, B, C) assert( B <= A && A <= C)

using namespace std;

#define DEBUG 0
#define CLOCK 0

int main(){
    string s;
    cin >> s;
    long count=0;
    int acount=0;
    long n;
    cin >> n;
    
    long length = s.length();
    for(int i=0;i<length;i++)
        {
        if(s[i]=='a')
           acount++; 
    }
    long k=0;
    count = (n/length)*acount;
    long j = (n/length)*length;
    while(j!=n)
        {
        if(s[k]=='a')
            count++;
        j++;
        k++;
    }
     cout<<count;
    return 0;
}
