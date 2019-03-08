/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/search-insert-position/submissions/
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int idx = -1;
        
        for (i = 0; i< nums.size(); i++) {
            if (target <= nums[i]) {
                idx = i;
                break;
            }
        }
        
        if (idx == -1)
            idx = i;
        
        return idx;
    }
};
