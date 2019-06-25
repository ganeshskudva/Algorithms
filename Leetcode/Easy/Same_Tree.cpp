/**
 * 100. Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSameTree(p, q);
    }
    
    bool checkSameTree(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;

        
        s1.push(root1);
        s2.push(root2);
        
        while(!s1.empty() && !s2.empty()){
            TreeNode* current1 = s1.top(); s1.pop();  // pop top 
            TreeNode* current2 = s2.top(); s2.pop();
           
            if ((current1 && !current2) || (!current1 && current2))
                return false;
            
            if ( current1 && current2 && current1->val != current2->val)
                return false;
            
            if(current1 != NULL && current2 != NULL){
                // push unvisited neighbours to stack | order matters here, if you reverse it 
                // it would still be a DFS but a symmetric one to preorder out of the 6 possible combinations.  
                s1.push(current1->right);
                s1.push(current1->left);
                
                s2.push(current2->right);
                s2.push(current2->left);
                
            }
        }
        
        if (s1.size() != s2.size())
            return false;
        else 
            return true;
    }
};
