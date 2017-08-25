/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/ANUMLA
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

// *************************************************


int readInt(int l, int r, string name){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int %s in range [%d, %d], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int %s in range [%d, %d], but found %d!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}

// *************************************************

int n;
multiset< int > s, new_s;

void solve()
{
    n = readInt( 1, 15, "N" );
    for ( int i = 0; i < ( 1 << n ); i++ ) s.insert( readInt( 0, 1000000000, "A[]" ) );
    while ( s.size() > 1 )
    {
        int delta = *( ++s.begin() );
        printf("%d ", delta);
        while ( s.size() )
        {
            multiset< int >::iterator i = s.begin();           
            int value_i = *i;
            s.erase( i );
            multiset< int >::iterator j = s.find( value_i + delta ); 
            s.erase( j );
            new_s.insert( value_i );
        }
        s.swap( new_s );
    }
    printf("\n"); s.clear();
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = readInt( 1, 50, "T" );
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
