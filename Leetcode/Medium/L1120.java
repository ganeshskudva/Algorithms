/**
 * 1120. Maximum Average Subtree
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
        private class Result {
        public int sum, size;
        public Result(int sum, int size) {
            this.sum = sum;
            this.size = size;
        }
    }
    
    private TreeNode subtree = null;
    private Result subtreeResult = null;
    
    public double maximumAverageSubtree(TreeNode root) {
        calcAvg(root);
        return ((double)subtreeResult.sum / subtreeResult.size);
    }
    
    private Result calcAvg(TreeNode root) {
        if (root == null) {
            return new Result(0, 0);
        }
        
        Result left = calcAvg(root.left);
        Result right = calcAvg(root.right);
        
        Result result = new Result(
            left.sum + right.sum + root.val,
            left.size + right.size + 1
        );
        
        if (subtree == null ||
            ((double)subtreeResult.sum / subtreeResult.size) < ((double)result.sum / result.size)) {
            subtree = root;
            subtreeResult = result;
        }
        
        return result;
    }
}
