// 961. N-Repeated Element in Size 2N Array
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(size_t i = 2; i < A.size(); ++i){
            if (A[i] == A[i - 1] || A[i] == A[i - 2]) return A[i];
        }
        return A[0];
    }
};
