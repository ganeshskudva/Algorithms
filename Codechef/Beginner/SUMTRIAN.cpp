#include <bits/stdc++.h>

using namespace std;
 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d",&n);
		int a[100][100];
		int i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j <= i; j++)
				scanf("%d",&a[i][j]);
		for (i = n-2; i >= 0; i--)
			for (j = 0; j <= i; j++)
				a[i][j] += a[i+1][j] > a[i+1][j+1] ? a[i+1][j] : a[i+1][j+1];
		printf("%d\n", a[0][0]);
	}
	return 0;
}