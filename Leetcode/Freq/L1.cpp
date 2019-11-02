// 1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>comp;
        for(int i = 0; i < nums.size(); i++) {
            int compli = target - nums[i];
            if(comp.find(compli) != comp.end()) {
                return {i, comp[compli]};
            }
            comp[nums[i]] = i;
        }
        return vector<int>();
    }
};
