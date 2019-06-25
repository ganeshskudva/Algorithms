/**
 * 101. Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> a;
    stack<TreeNode*> b;

    a.push(root);
    b.push(root);

    while(!a.empty() && !b.empty())
    {

        if(a.top() == NULL && b.top()==NULL)
        {
            a.pop();
            b.pop();
            continue;
        }

        if(a.top()==NULL)
            return false;
        if(b.top()==NULL)
            return false;

        if(a.top()->val != b.top()->val)
            return false;

        TreeNode* temp_a = a.top();
        TreeNode* temp_b = b.top();
        a.pop();
        b.pop();
        a.push(temp_a->left);
        a.push(temp_a->right);

        b.push(temp_b->right);
        b.push(temp_b->left);
    }
    
    if(a.empty() && b.empty())
        return true;

    return false;
    }
};
