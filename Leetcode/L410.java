class Solution {
    public int splitArray(int[] weights, int D) {
        if (weights == null || weights.length == 0 || D == 0)
            return 0;

        int max = Integer.MIN_VALUE, sum = 0;
        for (int i: weights) {
            max = Math.max(max, i);
            sum += i;
        }
        int l = max, r = sum, mid = 0;

        while (l < r) {
            mid = l + (r-l)/2;
            if (isValid(mid, D, weights))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
    
    private boolean isValid(int cap, int D, int[] weights) {
        int days = 1, sum = 0;
        for (int w: weights) {
            sum += w;
            if (sum > cap) {
                sum = w;
                days++;
            }
        }

        return days <= D;
    }
}
