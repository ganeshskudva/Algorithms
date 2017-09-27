/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/CHEFVOTE
*/


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
int a[MAXN], votes[MAXN];
int n;

int good()
{
	vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (votes[i] == i)
			return false;
		cnt[votes[i]]++;
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] != a[i])
			return false;
	return true;
}

int checkOk()
{
	int sum = 0;
	int ok = true;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (a[i] == n)
			ok = false;
	}
	if (n == 1 || sum != n)
		ok = false;
	return ok;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	assert(T >= 1 && T <= 500);
	while (T--)
	{
		cin >> n;
		assert(n >= 1 && n <= 50);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			assert(a[i] >= 0 && a[i] <= n);
		}	
		if (!checkOk())
			cout << -1 << endl;
		else 
		{
			memset(votes, 0, sizeof(votes));
			int j = 1;
			for (int i = 1; i <= n; i++)
			{
				int cnt = a[i];
				for (; j <= n && cnt --; j++)
					votes[j] = i;
			}
			while (true)
			{
				if (good())
					break;
				vector<int> badPos;
				for (int i = 1; i <= n; i++)
					if (votes[i] == i)
						badPos.push_back(i);
				assert(badPos.size() != 0);
				if (badPos.size() == 1)
				{
					int extra = 1;
					for (int i = 1; i <= n; i++)
						if (votes[i] != badPos[0])
							extra = i;
					swap(votes[badPos[0]], votes[extra]);
				}
				else 
				{
					swap(votes[badPos[0]], votes[badPos[1]]);
				}
			}
			for (int i = 1; i <= n; i++)
			{
				cout << votes[i];
				if (i != n)
					cout << " ";
				else 
					cout << endl;
			}
		}
	}
	return 0;
}
