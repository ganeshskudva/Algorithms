/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/SPRNMBRS
*/

#include <cstdio>
#include <cstring>
#include <cassert>

const long long INF = 1000000000000000000LL;

int main()
{
    int tests;
    for (assert(scanf("%d", &tests) == 1 && 1 <= tests && tests <= 1000); tests --; ) {
        long long l, r;
        assert(scanf("%lld%lld", &l, &r) == 2 && 1 <= l && l <= r && r <= INF);
        long long base = 2;
        int answer = 0;
		// only 2^a * 3^b are possible
        for (;base <= r; base *= 2) {
            long long x = base;
            for (;x <= r; x *= 3) {
                if (l <= x && x <= r) {
                    ++ answer;
                }
            }
        }
		// take care of 1
        if (l <= 1 && 1 <= r) {
            ++ answer;
        }
        printf("%d\n", answer);
    }
    return 0;
}
