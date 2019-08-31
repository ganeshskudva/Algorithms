/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> findLeaves(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
         
        if (root == null) {
            return ans;
        }
         
        findLeavesHelper(root, ans);
         
        return ans;
    }
     
    private int findLeavesHelper(TreeNode root, List<List<Integer>> ans) {
        if (root == null) {
            return -1;
        }
         
        int left = findLeavesHelper(root.left, ans);
        int right = findLeavesHelper(root.right, ans);
         
        int depth = Math.max(left, right) + 1;
         
        if (depth == ans.size()) {
            List<Integer> list = new ArrayList<>();
            list.add(root.val);
            ans.add(list);
        } else {
            List<Integer> list = ans.get(depth);
            list.add(root.val);
        }
         
         
        return depth;
    }
}
