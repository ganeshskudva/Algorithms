// 198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        if(n==0){return 0;}
        if(n==1){
            return nums[0];
        }
        if(n==2){
            if(nums[0]>nums[1]){
                return nums[0];
            }
            else{
                return nums[1];
            }
        }
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=dp[0]+nums[2];
        for(int i=3;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],nums[i]+dp[i-3]);
        }
        int max=0;
        for(int i=0;i<n;i++){
            if(dp[i]>max){
                max=dp[i];
            }
        }
        return max;
    }
};
