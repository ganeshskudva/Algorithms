// 204. Count Primes
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
bool* prime = (bool*)malloc(sizeof(bool)*n);
memset(prime, true, n);

for (int i = 2; i < n; i++){
    if ( !prime[i] ) continue;
    res++;
    for (int j = 2; i*j < n; j++){
        prime[i*j] = false;
    }
}
return res;
    }
};
