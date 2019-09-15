// 215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>,greater<> > q;
        int ret;
        
        for (int num: nums) {
            if (q.size() == k) {
                if (num < q.top())
                {
                    ret = q.top();
                    continue;
                }
                q.pop();
            }
            q.push(num);
            ret = q.top();
        }
        
        return ret;
    }
};
