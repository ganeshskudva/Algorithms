/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*
* Similar as
* 875. Koko Eating Bananas
* 774. Minimize Max Distance to Gas Station
*/

class Solution {
public:
     int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 25000000;
        for (int w: weights)
            left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int i = 0; i < weights.size() && need <= D; cur += weights[i++])
                if (cur + weights[i] > mid)
                    cur = 0, need++;
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
