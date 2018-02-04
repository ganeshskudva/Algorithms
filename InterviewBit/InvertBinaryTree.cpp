//https://www.interviewbit.com/problems/invert-the-binary-tree/
void invert(TreeNode* root){
    if(root == NULL){
        return;
    }
    
    invert(root->left);
    invert(root->right);
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
}

TreeNode* Solution::invertTree(TreeNode* root) {
    
    invert(root);
    
    return root;    
}
