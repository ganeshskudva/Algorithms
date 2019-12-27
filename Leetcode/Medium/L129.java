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
    public int sumNumbers(TreeNode root) {
        int result = 0;
        if (root == null) {
            return result;
        }

        Queue<TreeNode> nodeStoreQueue = new LinkedList<>();
        Queue<Integer> sumCountQueue = new LinkedList<>();
        nodeStoreQueue.offer(root);
        sumCountQueue.offer(root.val);

        while (!nodeStoreQueue.isEmpty()) {
            TreeNode current = nodeStoreQueue.poll();
            int currentSum = sumCountQueue.poll();

            if (current.left == null && current.right == null) {
                result += currentSum;
            }

            if (current.left != null) {
                nodeStoreQueue.offer(current.left);
                sumCountQueue.offer((currentSum * 10) + current.left.val);
            }
            if (current.right != null) {
                nodeStoreQueue.offer(current.right);
                sumCountQueue.offer((currentSum * 10) + current.right.val);
            }
        }
        return result;
    }
}
