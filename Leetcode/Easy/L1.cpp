class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> val;
        int i;
        vector<int> vec;
        
        for (i = 0; i < nums.size(); i++) {
            val[nums[i]] = i;
        }
        
        for (i = 0; i < nums.size(); i++) {
            if (val.find(target-nums[i]) != val.end() && 
                i != val[target-nums[i]]) {
                vec.push_back(i);
                vec.push_back(val[target-nums[i]]);
                break;
            }
        }
        
        return vec;
    }
};
