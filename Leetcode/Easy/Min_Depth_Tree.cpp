/**
 * 111. Minimum Depth of Binary Tree
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        return (root == nullptr)? 0 : 
        (root->left == nullptr && root->right == nullptr)? 1:
        (root->left == nullptr)? 1 + minDepth(root->right):
        (root->right == nullptr)? 1 + minDepth(root->left):
        1 + min(minDepth(root->left), minDepth(root->right));
    }
}
