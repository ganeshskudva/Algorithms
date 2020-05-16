class Solution {
int cnt, max;
    Map<TreeNode, Integer> mp;
    public int goodNodes(TreeNode root) {
        mp = new HashMap<>();
        cnt = 0;
        max = Integer.MIN_VALUE;
        dfs(root);
        return cnt;
    }

    private void dfs(TreeNode root) {
        if (root == null)
            return;

        if (mp.containsKey(root))
            return;
        mp.put(root, max);
        max = Math.max(max, root.val);
        if (root.val >= max)
            cnt++;

        dfs(root.left);
        dfs(root.right);

        max = mp.get(root);
        mp.remove(root);
    }
}
