/**
 * 701. Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == NULL) {
            return newNode;
        }
        
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        
        while (cur) {
            prev = cur;
            if (val > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
 
        }
        
        if (val > prev->val)
            prev->right = newNode;
        else 
            prev->left = newNode;
        
        return root;
    }
};
