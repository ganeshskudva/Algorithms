// 1016. Binary String With Substrings Representing 1 To N
class Solution {
public:
    string getBinary(int i) {
        string ans ="";
        while(i) {
            if(i%2) ans.push_back('1');
            else ans.push_back('0');
            i >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string S, int N) {
        for(int i=1; i <= N; i++) {
            if(S.find(getBinary(i)) == string::npos) return false;
        }
        return true;
    }
};
