#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000000 + 7;

int power(int k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return 2;
    if (k % 2 == 1)
        return power(k - 1) * 2LL % MOD;
    int q = power(k / 2);
    return q * 1LL * q % MOD;
}

int main(int argc, const char * argv[]) {
    int tn;
    
    cin >> tn;
    while (tn--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        cout << power(n - 1) - 2 << endl;
    }
    
    return 0;
}
