/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/LOSTMAX
*/


#include <bits/stdc++.h>
using namespace std;

int t;
string s;
vector <int> vec;

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> t;
	getline(cin , s);
	
	while(t--){
		vec.clear();
		
		getline(cin , s);
		
		int ans = 0 , res = 0;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == ' '){
				vec.push_back(res);
				res = 0;
			}else{
				res = res * 10 + (s[i] - '0');
			}
		}
		vec.push_back(res);
	
		bool fl = 0;
		int n = vec.size() - 1;
		for(int i = 0 ; i < vec.size() ; i++){
			if(!fl && n == vec[i]){
				fl = 1;
			}else{
				ans = max(ans , vec[i]);
			}
		}
		
		cout << ans << '\n';	
	}
}
