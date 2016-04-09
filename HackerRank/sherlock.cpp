#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long int ull;

using namespace std;

#define DEBUG 0

int main()
{
	ull t = 0, n = 0, i = 0;
	ull left = 0, right = 0;
	ull left_sum = 0, right_sum = 0;
	bool found = false;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
		found = false;
		left = 0;
		right = 0;
		left_sum = 0;
		right_sum = 0;
#if DEBUG
	 	n = (rand()%10)+1;
	 	cout << n << endl;
#else
	 	cin >> n;
#endif
	 	ull arr[n];
	 	memset(arr, 0 , n * sizeof(ull));

	 	for (i = 0; i < n; i++)
	 	{
#if DEBUG
	 		arr[i] = (rand()%10)+1;
	 		cout << arr[i] << " ";
#else
	 		cin >> arr[i];
#endif
	 	}
#if DEBUG
	 	cout << endl;
#endif

	 	if (n == 1)
	 	{
	 		cout << "YES"<<endl;
	 		continue;
	 	}
	 	left = 0;
	 	right = n-1;
	 	left_sum += arr[left];
	 	right_sum += arr[right];
	 	do
	 	{	
	 		if (left_sum > right_sum)
	 		{
	 			right--;
	 			right_sum += arr[right];
	 		}
	 		else if (right_sum > left_sum)
	 		{
	 			left++;
	 			left_sum += arr[left];
	 		}
	 		else
	 		{
	 			if (abs(left - right) == 2)
	 			{
	 				cout << "YES"<<endl;
	 				found = true;
	 				break;
	 			}
	 			left++;
	 			left_sum += arr[left];
	 			right--;
	 			right_sum += arr[right];
	 		}
	 	}while (left < right);
	 	if (!found)
	 	{
	 		cout << "NO"<<endl;
	 	}
	}

	return 0;
}