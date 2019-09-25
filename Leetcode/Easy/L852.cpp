// 852. Peak Index in a Mountain Array
class Solution {
public:
int peakIndexInMountainArray(vector<int>& A) {
        
        for(int i=1; i < A.size() - 1; i++)
            if(A[i-1] < A[i] && A[i] > A[i+1])
                return i;
        return 0;
    }
};
