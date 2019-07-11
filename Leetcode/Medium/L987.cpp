/**
 * 987. Vertical Order Traversal of a Binary Tree
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
    typedef map<int, map<int, vector<int>>> XYMap;
    void verticalTraversal(TreeNode* root, int x, int y, XYMap &xmap){
        if(root == NULL)
            return;
        xmap[y][x].push_back(root->val);
        verticalTraversal(root->left, x-1,y+1, xmap);
        verticalTraversal(root->right, x+1, y+1, xmap);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        XYMap xmap;
        int x = 0, y = 0;
        xmap[y][x].push_back(root->val);
        verticalTraversal(root->left, x-1, y+1, xmap);
        verticalTraversal(root->right, x+1, y+1, xmap);
        y = xmap.begin()->first;
        auto it = xmap.begin();
        for(++ it; it != xmap.end(); ++ it){
            for(auto xit=it->second.begin(); xit != it->second.end(); ++ xit){
                sort(xit->second.begin(), xit->second.end());
                for(int v: xit->second)
                    xmap[y][xit->first].push_back(v);
            }
        }
        for(auto xit=xmap[y].begin(); xit!=xmap[y].end(); ++ xit){
            res.push_back(move(xit->second));
        }
        return res;
    }
};
