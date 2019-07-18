// 1047. Remove All Adjacent Duplicates In String
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        string str;
        
        if (S.empty())
            return str;
            
        s.push(S[0]);
        for (int i = 1; i < S.size(); i++) {
            if (!s.empty()) {
                if (s.top() == S[i]) {
                    s.pop();
                    continue;
                }
            }
            s.push(S[i]);
        }
        
        while (!s.empty()) {
            str += s.top();
            s.pop();
        }
        
        return string(str.rbegin(), str.rend());
    }
};
