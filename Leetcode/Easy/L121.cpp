// 121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) { return 0; }
        int aResult = 0;
        int aMin = prices[0];
        for (int i=0;i<prices.size();i++) {
            int aRange = (prices[i] - aMin);
            aResult = max(aResult, aRange);
            aMin = min(aMin, prices[i]);
        }
        return aResult;
        
    }
};
