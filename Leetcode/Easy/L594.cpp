// 594. Longest Harmonious Subsequence
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        int maxRet = 0;
        
        if (nums.size() == 0)
            return 0;
        
        for (auto it : nums) {
            count[it]++;
        }
        
        map<int, int>::iterator it = count.begin();
        map<int, int>::iterator itPrev = count.begin();
        
        for (it++ ; it != count.end(); itPrev++, it++) {
            if (itPrev->first + 1 == it->first) {
                if (itPrev->second + it->second > maxRet) {
                    maxRet = itPrev->second + it->second;
                }
            }
        }
        
        return maxRet;
    }
};
