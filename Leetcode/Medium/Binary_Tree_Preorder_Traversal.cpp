/**
 * 144. Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> nodes;
        
        if(root == NULL) return preorder;
        
        while(root != NULL || !nodes.empty()){
            //push left children if available
            while(root != NULL){
                preorder.push_back(root->val);
                nodes.push(root);
                root = root->left;
            }
            
            //retrieve top node and store its right child if exists
            root = nodes.top();
            nodes.pop();
            
            root = root->right;
        }
        
        return preorder;
    
    }
};
