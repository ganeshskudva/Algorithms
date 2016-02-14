#include <bits/stdc++.h>

typedef unsigned long long int ull;
#define N 100001

using namespace std;

#define GETCHAR getchar_unlocked
inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
		c=GETCHAR();
		if(c=='\n'||c==' ') break;
		n = n * 10 + c - '0';
    }
    return n;
}

int main ()
{
	int t;
	ull i = 0;
	ull val = 0;
	ull arr[N];

	t = readInt();

	do 
	{
		for (i = 1; i <= t; i++)
		{
			arr[i] = readInt();
 		}

 		for (i = 1; i < t; i++)
 		{
 			if (arr[arr[i]] != i)
 			{
 				cout << "not ambiguous" << endl;
 				break;
 			}
 		}

 		if (i == t)
 		{	
 			cout << "ambiguous" << endl;
 		}

 		memset(arr, 0, N);

 		t = readInt();
	}while(t);

	return 0
}
