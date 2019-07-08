class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int zero = 0, czero = 0, one = 0, cone=0, len = S.length();
        bool flag = false;
        
        for(int i=0; i<len; i++) {
            if(S[i] == '0') {
                czero = zero;
                cone = 1+ min(zero, one);
            } else {
                cone = min(zero, one);
                czero = 1 + zero;
            }
            zero = czero;
            one = cone;
        }
        return min(zero, one);
    }
};
