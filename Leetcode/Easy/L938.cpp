/**
 * 938. Range Sum of BST
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode*> s;
        int sum = 0;
        
        if (root == NULL)
            return sum;
        
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            
            if (cur != NULL) {
                if (cur->val >= L && cur->val <= R) 
                    sum += cur->val;
                
                s.push(cur->left);
                s.push(cur->right);
            }
        }
        
        return sum;
    }
};
