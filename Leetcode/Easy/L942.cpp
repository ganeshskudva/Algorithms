// 942. DI String Match
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int D = N, I = 0;
        vector<int> res(N+1);
        for (int i = 0; i < N; i++) (S[i] == 'I' ? res[i] = I++: res[i] = D--);
        res[N] = (I + D) / 2;
        return res;
    }        
};
