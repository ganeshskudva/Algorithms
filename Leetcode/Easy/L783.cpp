/**
 * 783. Minimum Distance Between BST Nodes
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    void inorder(TreeNode* root, int &ans) {
        if(!root) return;
        inorder(root->left, ans);
        if(!prev) prev=root;
        else {
            ans = min(ans, root->val - prev->val);
            prev = root;
        }
        inorder(root->right, ans);
    }
    int minDiffInBST(TreeNode* root) {
        prev = NULL;
        int ans = INT_MAX;
        inorder(root, ans);
        return ans;
    }
};
