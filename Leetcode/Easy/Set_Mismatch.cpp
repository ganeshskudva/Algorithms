/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/set-mismatch/submissions/
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> numbers;
        int i = 0;
        vector<int> vec;
        int repeat, miss, sum = 0, actual, size = nums.size();
        
        for (i = 0; i < nums.size(); i++)
        {
            if (numbers.count(nums[i]) == 0)
                numbers.insert(nums[i]);
            else {
                repeat = nums[i];
            }
              
            sum += nums[i];
        }

        for (i = 0; i < nums.size(); i++) {
            if (numbers.count(i+1) == 0) {
                miss = i+1;
                break;
            }
        }
        
        vec.push_back(repeat);
        vec.push_back(miss);
        
        return vec;
    }
};
