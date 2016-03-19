#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
typedef unsigned long long int ull;

#define DEBUG 0

int main()
{
	ull t, n, m, s, mod_val;

#if DEBUG
		srand((unsigned)time(0));
		t = (rand()%1000)+1;
		cout<<"t: "<<t<<endl;
#else
	scanf("%llu",&t);
#endif

	while(t--)
	{
#if DEBUG
		n = (rand()%1000)+1;
		m = (rand()%1000)+1;
		s = (rand()%n)+1;
		cout<<n<<" "<<m<<" "<<s<<endl;
#else 
		scanf("%llu %llu %llu",&n, &m, &s);
#endif
		printf("%llu\n",((s+m)%n)-1);

	}

	return 0;
}
