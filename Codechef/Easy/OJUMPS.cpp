/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/OJUMPS
*/

#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

long long n;
bool flag;

int main (int argc, char * const argv[]) {
	cin >> n;
	assert(0 <= n && n <= 1000000000000000000LL);
	n %= 6; // there is a cycle of the size 6
	if (!n || n == 1 || n == 3) cout << "yes" << endl; else cout << "no" << endl; // check all the reachable cells in the cycle
    return 0;
}
