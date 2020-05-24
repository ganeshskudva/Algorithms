/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int cnt;
    public int pseudoPalindromicPaths (TreeNode root) {
        cnt = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        dfs(mp, root);

        return cnt;
    }

    private void dfs(Map<Integer, Integer> mp , TreeNode root) {
        if (root == null)
            return;

        mp.put(root.val, mp.getOrDefault(root.val, 0) + 1);
        if (root.left == null && root.right == null) {
            cnt += checkPsuedoPalin(mp);
        } else {
            dfs(mp, root.left);
            dfs(mp, root.right);
        }

        mp.put(root.val, mp.getOrDefault(root.val, 0) -1);
        if (mp.get(root.val) == 0)
            mp.remove(root.val);
    }

    private int checkPsuedoPalin(Map<Integer, Integer> mp) {
        int odd = 0;

        for (Integer key: mp.keySet()) {
            if (mp.get(key)%2 != 0)
                odd++;
            
            if (odd > 1)
                return 0;
        }
        
        return 1;
    }
}
