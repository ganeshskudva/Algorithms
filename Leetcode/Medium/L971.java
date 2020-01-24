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
public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        List<Integer> res = new ArrayList<>();
        int i = 0;
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        while (s.size() > 0) {
            TreeNode node = s.pop();
            if (node == null) continue;
            if (node.val != voyage[i++]) return Arrays.asList(-1);
            if (node.right != null && node.right.val == voyage[i]) {
                if (node.left != null) res.add(node.val);
                s.push(node.left);
                s.push(node.right);
            } else {
                s.push(node.right);
                s.push(node.left);
            }
        }
        return res;
    }
}
