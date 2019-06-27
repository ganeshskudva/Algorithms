/**
 * 872. Leaf-Similar Trees
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
    void getSeq(TreeNode* root, vector<int> &t) {
        if(!root) return;
        getSeq(root->left, t);
        if(!root->left && !root->right) {
            t.push_back(root->val);
        }
        getSeq(root->right, t);
    }
        
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 ||!root2) return false;
        vector<int> seq1;
        vector<int> seq2;
        getSeq(root1, seq1);
        getSeq(root2, seq2);
        if(seq1.size() != seq2.size()) return false;
        for(int i = 0; i < seq1.size(); i++) {
            if(seq1[i] != seq2[i]) return false;
        }
        return true;
    }
};
