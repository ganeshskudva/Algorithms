#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

typedef unsigned long long int ull;

using namespace std;

#define DEBUG 0

ull num_chars (std::string first,
			   std::string second)
{
	ull i = 0;
	ull cnt = 0;
	int arr_first[26];
	int arr_second[26];

	memset(arr_first, 0, 26 * sizeof(int));
	memset(arr_second, 0, 26 * sizeof(int));

	for (i = 0; i < first.length(); i++)
	{
		arr_first[int(first[i]) - 'a']++;
	}

	for (i = 0; i < second.length(); i++)
	{
		arr_second[int(second[i]) - 'a']++;

	}

	for (i = 0; i < 26; i++)
	{
		cnt += abs(arr_first[i] - arr_second[i]);

	}

	return cnt;
}

int main()
{
	std::string first, second;
#if 0
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<N<<endl;
#else 
	cin >> t;
#endif 
#endif

	cin >> first >> second;

	cout << num_chars(first, second) << endl;

	return 0;
}