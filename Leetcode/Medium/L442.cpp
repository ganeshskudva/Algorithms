// 442. Find All Duplicates in an Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> rst;
        
        for (int i=0;i<nums.size();i++)
        {
            int index = abs(nums[i])-1; // -1 since the range is 1 to n
            if (nums[index] > 0)
            {
                // First time see
                nums[index] = -nums[index];
            } else {
                // Second time see
                rst.push_back(index+1); // compensate for the -1 previously
            }
        }
        
        return rst;
    }
};
