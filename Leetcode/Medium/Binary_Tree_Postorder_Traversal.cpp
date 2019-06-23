/**
 * 145. Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
      stack<TreeNode*> st;
        vector<int> res;
        TreeNode *prev;
        if(!root) return res;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            while(root->left){
                root=root->left;
                st.push(root); 
            }
            while(!(root->right) || (root->right==prev)){
                res.push_back(root->val);
                prev=root;
                st.pop();
                if(st.empty()) return res;
                root=st.top();
                cout<<root->val<<endl;
            }
            st.push(root->right);
        }
        return res;
    }
};
