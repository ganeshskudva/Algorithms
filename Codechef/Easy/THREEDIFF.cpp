/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     THREEDIF - Three Different Numbers
 * Author:      Anton Lunyov (Problem-Setter and Editorialist)
                (inspired by the solution of Hiroto Sekido who was kind to test the problem)
 * Complexity:  O(1) per test
 * Timing:      0.000 out of 2.013
 *
 * Description:
 * If we sort numbers N1, N2, N3 the answer remains the same.
 * Hence let's assume that N1 <= N2 <= N3.
 * Then for X1 we have N1 choices, for X2 we have N2-1 choices
 * (indeed X2 can be any number from 1 to N2 not equal to X1;
 * since X1<=N1<=N2, there are N2-1 such numbers)
 * and for X3 we have N3-2 choices
 * (similarly X3 can be any number from 1 to N3 not equal to X1 and X2;
 * since X1<=N1<=N3, X2<=N2<=N3 and they are different, there are N3-2 such numbers)
 * By basic combinatorics the answer is the product of N1, N2-1 and N3-2.
 */
#include <iostream>
#include <algorithm>
using namespace std;

// the modulo 10^9 + 7
const int MOD = 1000000007;

// the solution below solves correctly the same problem
// where we have to count number of arrays of length K
// having all elements different where each element belongs to 
// its own range [1, Ni]
const int K = 3;

int main() {
	// input number of tests
	int T;
	cin >> T;

	// loop over tests
	for (int t = 0; t < T; ++t) {

		// input and sort numbers N[i]
		long long N[K];
		for (int i = 0; i < K; ++i) {
			cin >> N[i];
		}
		sort(N, N + K);

		// calculate the answer by the formula: product of N[i]-i for 0 <= i < K
		// init by 1 as usually for products
		int ans = 1;
		for (int i = 0; i < K; ++i) {
			// N[i] - i could be negative
			// but then for some j < i we should have N[j] - j = 0
			// so the answer will be already zero
			// hence such code is safe and can't produce negative result
			ans = (N[i] - i) % MOD * ans % MOD;
			// note also that the order of numbers is important here
			// writing ans % MOD * (N[i] - i) % MOD leads to long long overflow
		}

		// output the answer
		cout << ans << endl;
	}
}
