// 1138. Alphabet Board Path
class Solution {
public:
    void add(int n, char c, string &s) {
        for(int i = 1; i <= n; i++) s+=c;
    }
    string alphabetBoardPath(string target) {
        string ans;
        int prev_r = 0, prev_c = 0;
        for(int i = 0; i < target.size(); i++) {
            int cur_r = (target[i] - 'a')/5;
            int cur_c = (target[i] - 'a')%5;
            
            if(cur_c < prev_c) add(prev_c - cur_c, 'L', ans);
            if(cur_r < prev_r) add(prev_r - cur_r, 'U', ans);
            if(cur_c > prev_c) add(cur_c - prev_c, 'R', ans);
            if(cur_r > prev_r) add(cur_r - prev_r, 'D', ans);
            
            add(1, '!', ans);
            prev_r = cur_r;
            prev_c = cur_c;
        }
        return ans;
    }
};
