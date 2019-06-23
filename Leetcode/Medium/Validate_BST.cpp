/**
 * 98. Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL) return true;
        
        stack<TreeNode*> s;
        TreeNode* prev = NULL;
        
        while(root != NULL || !s.empty()){
            while(root != NULL){
                s.push(root);
                root = root->left;
            }    
            
            root = s.top(); s.pop();
            if(prev != NULL && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        
        return true;
        
    }
};
