#include <bits/stdc++.h>
#include <sstream>

typedef long long int ll;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;

#define GETCHAR getchar_unlocked
inline ll readInt() 
{
    ll n = 0;
    char c;
    while (1)
    { 
		c=GETCHAR();
		if(c=='\n'||c==' ') break;
		n = n * 10 + c - '0';
    }
    return n;
}


int get_int(string str, int pos)
{
	return (str.at(pos) - '0');
}

ll reverse(ll n)
{
	ll sum = 0;
	int flag = 0;

	std::string str = patch::to_string(n);

	sum += get_int(str, 0);
	sum += get_int(str, (str.length() - 1));

	return sum;
}

int main()
{
	ll t,a;

	scanf("%lld",&t);

	while (t--)
	{
		scanf("%lld",&a);
		printf("%lld\n",reverse(a));
	}

	return 0;
}
