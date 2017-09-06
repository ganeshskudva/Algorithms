/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/ASTRING
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


string s;

vector<int > X[26];

int main() {
  int t;
  cin>>t;
  while(t--) {
    cin >> s;
    int k; 
    cin>>k;
    int n = s.size();
    for(int i = 0; i < 26; i++)
	 X[i].clear();
    for(int i = 0; i < n; i++) {
      X[s[i]-'a'].push_back(i);
    }
    for(int i = 0; i < 26; i++)
	 reverse(X[i].begin(),X[i].end());

    string ans = "";
    int last = -1;
    while(k) {
      for(int i = 0; i < 26; i++) {
        while(X[i].size() && X[i].back() < last) X[i].pop_back();
        if(X[i].size() && X[i].back() + k <= n) {
          ans += i + 'a';
          last = X[i].back();
          X[i].pop_back();
          break;
        }
      }
      k--;
    }
    cout << ans << "\n";
  }
  return 0;
}
