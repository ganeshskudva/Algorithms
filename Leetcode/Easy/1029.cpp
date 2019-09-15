// 1029. Two City Scheduling
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto &a, auto &b){
            return abs(a[0] - a[1]) > abs(b[0] - b[1]);
        });
        int ans = 0;
        int n = costs.size() / 2;
        int a = n, b = n;
        for(int i = 0; i < costs.size(); ++i ) {
            auto &c = costs[i];
            if(c[0] > c[1] && b > 0) {
                ans += c[1];
                --b;
            }else if(c[0] < c[1] && a >0) {
                ans += c[0];
                --a;
            }else if( b > 0) {
                ans += c[1];
                --b;
            }else if( a > 0) {
                ans += c[0];
                --a;
            }
        }
        return ans;
    }
};
