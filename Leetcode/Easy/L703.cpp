class KthLargest {
public:
    int kth;
    std::priority_queue<int,std::vector<int>,greater<> > q;

    KthLargest(int k, vector<int>& nums)
    : kth(k)
    {
        for(int a : nums) (void)add(a);
    }

    int add(int val) 
    {
        if (q.size() == kth)
        {
            if (val < q.top())
            {
                return q.top();
            }
            q.pop();
        }
        q.push(val);
        return q.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
