/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerearth.com/problem/algorithm/little-shino-and-the-tournament
*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 100031;
int n, tests;
int level[N];
vector<pair<int, int> > v;
int ans[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> tests;
	for (int i = 0; i < n; i++)
	{
		cin >> level[i];
	}
	v.clear();
	for (int i = 0; i < n; i++)
	{
		v.push_back(make_pair(level[i], i));
	}
	for (int i = 0; i < n; i++)
		ans[i] = 0;
	while (v.size()>1)
	{
		vector<pair<int, int> > v2;
		for (int i = 0; i < v.size(); i += 2)
		{
			if (i + 1 == v.size())
			{
				v2.push_back(v[i]);
				continue;
			}
			ans[v[i].second]++;
			ans[v[i + 1].second]++;
			if (v[i].first>v[i + 1].first)
				v2.push_back(v[i]);
			else
				v2.push_back(v[i + 1]);
		}
		v = v2;
	}
	for (; tests; --tests)
	{
		int val;
		cin >> val;
		--val;
		cout << ans[val] << "\n";
	}
	return 0;
}
