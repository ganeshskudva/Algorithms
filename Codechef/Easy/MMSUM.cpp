/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/MMSUM
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define left Left
#define right Right

const int INF = 2000000000;
const int MAXN = 100000 + 10;

long long left[MAXN];
long long right[MAXN];
long long a[MAXN];
int n;

int main(int argc, const char * argv[]) {
    int tn;
    cin >> tn;
    while (tn--) {
        cin >> n;
        
        long long best = -INF;
        long long minPrefix = 0;
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            best = max(best, sum - minPrefix);
            left[i] = sum - minPrefix;
            minPrefix = min(minPrefix, sum);
        }
        
        long long minSuffix = 0;
        sum = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            sum += a[i];
            right[i] = sum - minSuffix;
            minSuffix = min(minSuffix, sum);
        }
        
        for(int i = 0; i < n; i++) {
            long long current = 0;
            if (i > 0)
                current += left[i - 1];
            if (i < n - 1)
                current += right[i + 1];
            best = max(best, current);
        }
        
        cout << best << endl;
    }
    return 0;
}
