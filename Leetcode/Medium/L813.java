class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int[] sum = new int[A.length];
        for (int i = 0;i < A.length; i++) sum[i] = A[i] + (i > 0 ? sum[i-1] : 0); 
        double[] dp = new double[A.length];
        
        for (int groups = 1; groups <= K; groups++) {
            for (int s = 0; s + groups <= A.length; s++) {
                if (groups == 1) {
                    dp[s] = ((double)(sum[A.length-1] - sum[s] + A[s]) / (A.length-s));
                    continue;
                }
                for (int e = s; e + groups <= A.length; e++) {
                    dp[s] = Math.max(dp[s], (dp[e+1] + (double) (sum[e] - sum[s] + A[s]) / (e - s + 1)));
                }
            }
        }
        return dp[0];
    }
}
