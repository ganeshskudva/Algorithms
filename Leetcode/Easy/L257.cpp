/**
 * 257. Binary Tree Paths
 *
 * BFS iterative with map
 *
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
    vector<string> binaryTreePaths(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parents;
        vector<string> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (!tmp->left && !tmp->right) {
                //output;
                string res = to_string(tmp->val);
                TreeNode* cur = tmp;
                while(cur = parents[cur]) {
                    res = to_string(cur->val) + "->" + res;
                }
                ans.push_back(res);
            }
            
            if (tmp->left) {
                q.push(tmp->left);
                parents[tmp->left] = tmp;
            }
            
            if (tmp->right) {
                q.push(tmp->right);
                parents[tmp->right] = tmp;
            }
        }
        return ans;
    }
};

/**
 * 257. Binary Tree Paths
 *
 * FFS iterative with pair
 *
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr) return res;
        stack<pair<TreeNode*, string>> my_stack;
        my_stack.push(make_pair(root, to_string(root->val)));
        while(!my_stack.empty()) {
            pair<TreeNode*, string> temp = my_stack.top();
            my_stack.pop();
            TreeNode *node = temp.first;
            string path = temp.second;
            if(node->left == nullptr && node->right == nullptr) {
                res.push_back(path);
            }
            else {
                if(node->right != nullptr) {
                    my_stack.push(make_pair(node->right, path + "->" + to_string(node->right->val)));
                }
                if(node->left != nullptr) {
                    my_stack.push(make_pair(node->left, path + "->" + to_string(node->left->val)));
                }
            }
        }
        return res;
    }
};
