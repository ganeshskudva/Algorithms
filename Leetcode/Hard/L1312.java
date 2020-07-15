class Solution {
public int minInsertions(String s) {
        return s.length() - lcsTopDown(new StringBuilder(s).reverse().toString(), s, s.length(), s.length());
    }

    private int lcsTopDown(String s1, String s2, int m, int n) {
        int[][] dp = new int[m+1][n+1];
        int i,j;

        for (i = 0; i <= n; i++ )
            dp[0][i] = 0;
        for (j = 0; j <= n; j++)
            dp[j][0] = 0;

        for ( i = 1; i <= m; i++) {
            for ( j = 1; j <= n; j++) {
                if (s1.charAt(i-1) == s2.charAt(j-1))
                    dp[i][j] = 1 + dp[i-1][j-1];
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
}
