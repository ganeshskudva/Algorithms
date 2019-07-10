// 268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        int sum = 0,n = nums.size();
        int exp = (n *(n+1))/2;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        return exp - sum;
    }
};
