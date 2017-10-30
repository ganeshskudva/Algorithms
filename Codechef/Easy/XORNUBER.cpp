#include <cstdio>
#include <cstdlib>
#include <cassert>

int main(int argv, char** argc)
{
	int T,N;
	scanf("%d",&T);
	assert(T>0 && T<=100);
	while(T--)
	{
		scanf("%d",&N);
		assert(N>0 && N<=(1<<30));
		if(N==1)
		{
			printf("2\n");
		}
		//if N+1 is power of two
		else if(((N+1)&N)==0)
		{
			printf("%d\n",N/2);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
} 
