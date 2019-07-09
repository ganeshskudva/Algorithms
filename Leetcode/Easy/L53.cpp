// 53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax = nums.size() >0 ? nums[0] : 0;
        int sum = 0;
        for (int i=0; i <nums.size(); i++) {
            sum = max (nums[i], sum + nums[i]);
            curmax = max(curmax, sum);               
        }
        return curmax;
    }
};
