#include <bits/stdc++.h>

typedef long long int ull;

using namespace std;

#define DEBUG 		0
#define MOD		 	(1000000000 + 7)

ull fast_exp(ull base, ull exp) {

	if(exp==0 || base==1)
		return 1;
	if(exp==1)
		return base;
    ull res=1;
    while(exp>0) 
    {
       if(exp%2) 
       	{
       		res=(res*base)%MOD;
       	}
       
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}

int main()
{
	ull t = 0, n, k;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%20)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
#if DEBUG 
		n = (rand()%10)+1; 
		k = (rand()%10)+1;
		cout << n<<" "<<k<<endl;
#else
		cin >>n>>k;
#endif
		if (n == 1)
		{
			cout << k << endl;
		}
		else
		{
			ull res = fast_exp((k - 1), (n - 1));
			printf("%lld\n",(k * res)%MOD);
		}
	}

	return 0;
}