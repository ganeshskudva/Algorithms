class Solution {
int maxLength;
    public int longestConsecutive(TreeNode root) {
        maxLength = 0;
        dfs(root, null, 0);
        return maxLength;
    }

    public void dfs(TreeNode root, TreeNode prev, int sum) {
        if (root == null)
            return;

        if (prev != null && prev.val+1 == root.val)
            sum++;
        else
            sum = 1;

        maxLength = Math.max(maxLength, sum);
        dfs(root.left, root, sum);
        dfs(root.right, root, sum);


    }
}
