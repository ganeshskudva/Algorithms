class Solution {
public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        // Build memo for Memorization during DFS.
        int[][] memo = buildMemo(n);
        
        int scoreFirst = predictTheWinnerInSituation(nums, 0, n - 1, memo); // Final score of the first player.
        int scoreTotal = getTotalScores(nums);
        
        // Compare final scores of two players.
        return scoreFirst >= scoreTotal - scoreFirst;
    }
    
    private int predictTheWinnerInSituation(int[] nums, int i, int j, int[][] memo) {
        // Base case.
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return nums[i];
        }
        if (memo[i][j] != -1)
            return memo[i][j];
        
        // Recursive case.
        int curScore = Math.max(
            nums[i] + Math.min(predictTheWinnerInSituation(nums, i + 2, j, memo), predictTheWinnerInSituation(nums, i + 1, j - 1, memo)),
            nums[j] + Math.min(predictTheWinnerInSituation(nums, i, j - 2, memo), predictTheWinnerInSituation(nums, i + 1, j - 1, memo)));   
        memo[i][j] = curScore;
        
        return curScore;
    } 
    
    private int[][] buildMemo(int n) {
        int[][] memo = new int[n][n];
        
        for (int[] memoRow : memo)
            Arrays.fill(memoRow, -1);
        return memo;
    }
    
    private int getTotalScores (int[] nums) {
        int scoreTotal = 0;
        for (int num : nums) {
            scoreTotal += num;
        }
        
        return scoreTotal;
    }
}
