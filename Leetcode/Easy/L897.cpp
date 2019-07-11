/**
 * 897. Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        TreeNode* cur = root, *prev = &dummy;
        while(cur) {
            if(!cur->left) {
                prev->right = cur;
                prev = cur;
                cur = cur->right;
            }else {
                TreeNode* pred = cur->left;
                while(pred->right && pred->right!= cur) pred = pred->right;
                if(!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                }else {
                    cur->left = nullptr;
                    prev->right = cur;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return dummy.right;
    }
};
