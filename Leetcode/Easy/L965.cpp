/**
 * 965. Univalued Binary Tree
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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        if (root == NULL)
            return false;
        int val = root->val;
        q.push(root);
        
        
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            if (cur && cur->val != val)
                return false;
            
            if (cur != NULL) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        return true;
    }
};
