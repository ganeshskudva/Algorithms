/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/count-strings/problem
*/


#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <unordered_set>
#include <deque>
#include <unordered_map>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <assert.h>
#include <bitset>
#include <cstring>


using namespace std;

vector<vector<pair<int, int>>> Graph;
vector<pair<int, int>> DFA;
vector<vector<int>> Matrix;

void buildNFA(string &S, int &index, int incoming, int outgoing)
{
	if (S[index] == 'a')
	{
		Graph[incoming].push_back({ outgoing, 1 });
		index++;
		return;
	}

	if (S[index] == 'b')
	{
		Graph[incoming].push_back({ outgoing, 2 });
		index++;
		return;
	}

	int middle1= Graph.size();
	Graph.push_back(vector<pair<int, int>>());
	int middle2 = Graph.size();
	Graph.push_back(vector<pair<int, int>>());

	index++;
	buildNFA(S, index, middle1, middle2);

	if (S[index] == '*')
	{
		Graph[middle2].push_back({ middle1, 0 });
		Graph[incoming].push_back({ middle2, 0 });
		Graph[middle2].push_back({ outgoing, 0 });
		index += 2;
		return;
	}

	if (S[index] == '|')
	{
		Graph[incoming].push_back({ middle1, 0 });
		Graph[middle2].push_back({ outgoing, 0 });
		index++;
		buildNFA(S, index, middle1, middle2);
		index++;
		return;
	}
		
	Graph[incoming].push_back({ middle1, 0 });
	buildNFA(S, index, middle2, outgoing);

	index++;
	return;
}

vector<char> visited;
vector<int> final_state;
vector<int> epsilon;

void dfs_epsilon(int node)
{
	if (visited[node]) return;
	visited[node] = true;
	
	epsilon.push_back(node);

	for (pair<int, int> e : Graph[node])
		if (e.second == 0) dfs_epsilon(e.first);
}

void dfs(vector<int> state, int type)
{
	visited = vector<char>(Graph.size(), false);
	epsilon.clear();
	for (int node : state)
	for (pair<int, int> a : Graph[node])
	if (a.second == type)
		dfs_epsilon(a.first);
}

void NFAtoDFA()
{
	map<vector<int>, int> E;
	vector<vector<int>> State;
	int nnodes = 0;

	DFA.clear();
	DFA.push_back({ -1, -1 });

	epsilon.clear();
	visited = vector<char>(Graph.size(), false);
	dfs_epsilon(0);
	sort(epsilon.begin(), epsilon.end());
	State.push_back(epsilon);
	E[epsilon] = nnodes++;

	for (int node = 0; node < nnodes; node++)
	{
//		visited = vector<char>(Graph.size(), false);
		dfs(State[node], 1);
		sort(epsilon.begin(), epsilon.end());
		if (epsilon.size() > 0)
		{
			if (!E.count(epsilon))
			{
				E[epsilon] = nnodes++;
				State.push_back(epsilon);
				DFA.push_back({ -1, -1 });
			}
			DFA[node].first = E[epsilon];
		}

//		visited = vector<char>(Graph.size(), false);
		dfs(State[node], 2);
		sort(epsilon.begin(), epsilon.end());
		if (epsilon.size() > 0)
		{
			if (!E.count(epsilon))
			{
				E[epsilon] = nnodes++;
				State.push_back(epsilon);
				DFA.push_back({ -1, -1 });
			}
			DFA[node].second = E[epsilon];
		}
	}

	Matrix = vector<vector<int>>(nnodes, vector<int>(nnodes));
	for (int node = 0; node < nnodes; node++)
	{
		if (DFA[node].first != -1) Matrix[node][DFA[node].first]++;
		if (DFA[node].second != -1) Matrix[node][DFA[node].second]++;
	}

	final_state = vector<int>();
	for (int i = 0; i < nnodes; i++)
	if (find(State[i].begin(), State[i].end(), 1) != State[i].end()) final_state.push_back(i);
}

void mmult(vector<vector<int>> &D, vector<vector<int>> &S)
{
	vector<vector<int>> R(D.size(), vector<int>(D.size()));
	for (size_t x = 0; x < D.size(); x++)
	for (size_t y = 0; y < D.size(); y++)
	{
		long long s = 0;
		for (size_t i = 0; i < D.size(); i++)
			s = (s + D[x][i] * 1ll * S[i][y]) % 1000000007;
		R[x][y] = (int)s;
	}

	swap(D, R);
}

void mexp(vector<vector<int>>&M, int power)
{
	vector<vector<int>> R(M.size(), vector<int>(M.size()));
	for (size_t i = 0; i < M.size(); i++) R[i][i] = 1;

	while (power > 0)
	{
		if (power & 1) mmult(R, M);
		power >>= 1;
		if (power > 0) mmult(M, M);
	}
	swap(R, M);
}


int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	while (n--)
	{
		string S;
		int L;
		cin >> S >> L;

		Graph.clear();
		Graph.push_back(vector<pair<int, int>>());
		Graph.push_back(vector<pair<int, int>>());
		int index = 0;
		buildNFA(S, index, 0, 1);
		NFAtoDFA();

//		for (size_t i = 0; i < Matrix.size(); i++)
//			cout << i << " : " << setw(3) << setfill(' ') << DFA[i].first << " " << setw(3) << setfill(' ') << DFA[i].second << "\n";

		mexp(Matrix, L);

		long long s = 0;
		for (int j : final_state)
		{
//			cout << j << " ";
			s += Matrix[0][j];
		}

		cout << s % 1000000007 << "\n";

//		cout << "\n";
	}
}
