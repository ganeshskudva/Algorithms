/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/
*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> nums;
        int min=0;
        for(int i = 1; i <= 6; i++)
        {
            int changeA=0,changeB=0;
            for(int j = 0; j < A.size(); j++)
            {
                if(A[j] != i && B[j] !=i)
                {break;}
                if(A[j] == i && B[j] !=i)
                    changeB++;
                if(A[j] != i && B[j] ==i)
                    changeA++;
                if(j == A.size()-1)
                {
                    nums.push_back(i);
                    min = changeA<changeB?changeA:changeB;
                }
            }
        }
        if(nums.empty()) return -1;
        return min;
    }
};
