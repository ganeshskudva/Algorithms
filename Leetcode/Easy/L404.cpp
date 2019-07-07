/**
 * 404. Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> s;
        int sum = 0;
        int cnt = 1;
        
        if (root == NULL) {
            return sum;
        }
        
        s.push(root); 
        while (!s.empty()) {
            TreeNode* current = s.top(); s.pop();  // pop top 
            
            if (current != NULL) {
                s.push(current->right);
                s.push(current->left);
                
                if (current->left != NULL && current->left->left == NULL && current->left->right == NULL)
                    sum += current->left->val;
            }
        }
        
        return sum;
    }
};
