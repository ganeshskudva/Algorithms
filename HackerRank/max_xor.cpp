#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

typedef long long int ull;

using namespace std;

#define DEBUG 0

int main()
{
	ull l = 0, r = 0;
	ull max = 0;
	ull A = 0, B= 0, i = 0;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> l>>r;
#endif 

	A = l;
	B = l+1;
	i = l;
	while (i <= r)
	{
		if (max < (A ^ B))
		{
			max = A ^ B;
		}

		A = B;
		B = i;
		i++;
	}

	cout << max<< endl;

	return 0;
}