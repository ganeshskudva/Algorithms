/**
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        while (true) {
            if (root.val - p.val > 0 && root.val - q.val > 0)
                root = root.left;
            else if (root.val - p.val < 0 && root.val - q.val < 0)
                root = root.right;
            else 
                break;
        }
        
        return root;
    }
}
