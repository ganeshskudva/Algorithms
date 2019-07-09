// 238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int> & nums) {
        int s = nums.size();
        vector<int> forward(s, 1);
        for (int i = 0; i < s - 1; ++i)
            forward[i+1] = forward[i] * nums[i];
        int prod = nums[s-1];
        for (int i = 0; i < s-1; ++i) {
            forward[s-2-i] *= prod;
            prod *= nums[s-2-i];
        }
        return forward;
    }
};
