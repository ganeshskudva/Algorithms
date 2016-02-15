#include <bits/stdc++.h>

typedef long double ld;

using namespace std;

int main ()
{
	int t = 0;
	ld Cmin, Cmax;
	ld B, A;

	cin >> t;

	while (t--)
	{
		cin >> A;
		cin >> B;

		Cmax = hypotl(A, B);
		Cmin = sqrt(pow(B,2) - pow(A,2));

		cout <<(ld)Cmin<<" "<<(ld)Cmax<<endl;

	}

	return 0;
}
