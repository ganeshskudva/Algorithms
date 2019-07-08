/**
 * 102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // array of arrays to store final result 
        vector<int> levelresult;    // array storing result for each level temporarily
        
        queue<TreeNode*> bfs;       // bfs queue
        TreeNode* marker = new TreeNode(INT_MIN);  // dummy node to mark end of level
        
        bfs.push(root);
        bfs.push(marker);
        
        while(!bfs.empty()){
            TreeNode* current = bfs.front(); bfs.pop(); // pop from front or standard dequeue
            
            if(current){
                // if dummy node popped from queue means a level has ended 
                if(current->val == INT_MIN){
                    result.push_back(levelresult); // store level result
                    levelresult = vector<int>(0);  // initialize levelresult for next level
                    
                    // if queue not empty after removing marker, meaning a next level exists or null nodes remaining
                    if(!bfs.empty()) bfs.push(marker);
                }
                else{
                    levelresult.push_back(current->val); // storing current level values into levelresult            
                    
                    // kids pushed at back of queue ( standard enqueue operation )
                    bfs.push(current->left); 
                    bfs.push(current->right);
                }
            }
        }
        
        result.pop_back();
        return result;
    }
};


/*******************Without using dummy node *********************/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
   vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode*> q;
       vector<vector<int>> v;
       if(!root)   return v;
       q.push(root);
       while(!q.empty()){
           vector<int> cur;
           int len=q.size();
           for(int i=0;i<len;i++){
               cur.push_back(q.front()->val);
               if(q.front()->left)   q.push(q.front()->left);
               if(q.front()->right)    q.push(q.front()->right);
               q.pop();
           }
           v.push_back(cur);
       }
       return v;
   }
};
