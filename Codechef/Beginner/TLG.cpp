#include <bits/stdc++.h>

using namespace std;
#define gc getchar_unlocked
 
int fastin()
{
 
	register int c = gc();
	int n=0;
	for( ; (c<48 || c>57) ; c = gc());
	for( ; (c>47 && c<58) ; c=gc())
	{
		n = (n<<1) + (n<<3) + c - 48;
	}
	return n;
}
 
int main()
{
	int t,x=0,y=0,z=0,p;
 
	t= fastin();
	
	while(t--)
	{
 
		x = x + fastin();
		y = y + fastin();
 
		if(abs(x-y)>=z)
		{
			z = abs(x-y);
			p = x>y ? 1:2;
		}
	}
	
	printf("%d %d",p,z);
	return 0;
}