/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (!i || n > nums[i-1])
            nums[i++] = n;
    return i;
    }
};
