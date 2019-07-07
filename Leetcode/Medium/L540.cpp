// 540. Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            val ^= nums[i];
        }
        
        return val;
    }
};
