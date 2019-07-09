// 697. Degree of an Array
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
       unordered_map<int,vector<int>> m;
        for (int i = 0;i < nums.size();i ++)
        {
            m[nums[i]].push_back(i);
        }
        int degree = INT_MIN;
        for (auto i : m)
        {
            degree = max(degree,(int)i.second.size());
        }
        int res = INT_MAX;
        for (auto i : m)
        {
            if (i.second.size() == degree)
            {
                int t = i.second[i.second.size() - 1] - i.second[0] + 1;
                res = min(res,t);
            }
        }
        return res;
    }
};
