// 347. Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        priority_queue<pair<int, int>> elements;
        
        for (auto n : nums) {
            if (table[n]) {
                table[n]++;
            } else {
                table[n] = 1;
            }
        }
        
        
        for (auto it : table) {
            elements.push({it.second, it.first});
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            auto p = elements.top(); elements.pop();
            res.push_back(p.second);
        }
        
        return res;
    }
};
