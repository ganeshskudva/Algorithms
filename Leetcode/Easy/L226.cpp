/**
 * 226. Invert Binary Tree
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
TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>q1;
        q1.push(root);
        if (root == NULL)
            return NULL;
        while (!q1.empty()){
            TreeNode* current= q1.front();
            q1.pop();
            
            if (current != NULL){
                if ((current->left != NULL) && (current->right != NULL)){
                    TreeNode* temp= current->left;
                    current->left= current->right;
                    current->right= temp;
                    q1.push(current->left); q1.push(current->right);
                }
                else if ((current->left == NULL) && (current->right != NULL)){
                    current->left= current->right;
                    current->right= NULL;
                    q1.push(current->left); q1.push(current->right);
                }
                else if ((current->left != NULL) && (current->right == NULL)){
                    current->right= current->left;
                    current->left= NULL;
                    q1.push(current->left); q1.push(current->right);
                }
            }
        }
        return root;
    }
};
