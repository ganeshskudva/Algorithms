// 611. Valid Triangle Number
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int res = 0, second = 0;
        for(int first = 0; first < nums.length - 2; ++first) {
            second = first + 1;
            for(int third = first + 2; third < nums.length; ++third) {
                while(second < third && nums[first] + nums[second] <= nums[third])
                    second++;
                res += third - second;
            }
        }
        return res;
    }
}
