// 1144. Decrease Elements To Make Array Zigzag
const int INF = 1e9 + 5;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int sums[2] = {0, 0};

        for (int i = 0; i < n; i++) {
            int left = i == 0 ? INF : nums[i - 1];
            int right = i == n - 1 ? INF : nums[i + 1];
            int goal = min(left, right) - 1;

            if (nums[i] > goal)
                sums[i % 2] += nums[i] - goal;
        }

        return min(sums[0], sums[1]);
    }
};
