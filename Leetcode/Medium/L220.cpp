// 220. Contains Duplicate III
class Solution {
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector< pair<long, int> > vec;
        for (int i = 0; i < nums.size(); ++i) {
            vec.push_back(make_pair(nums[i], i));
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            while(j < nums.size() && vec[j].first-vec[i].first <= t) {
                if (abs(vec[j].second-vec[i].second) <= k) return true;
                j++;
            }
        }
        return false;
    }
};
