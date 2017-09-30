#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n, Tn, a[1000000 + 100];

int main () {
	ios_base::sync_with_stdio(false);
	cin >> Tn;
	while (Tn--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		if (n == 1 || a[0] == a[1])
			cout << 0 << endl;
		else
			cout << n << endl;
	}
	return 0;
}
