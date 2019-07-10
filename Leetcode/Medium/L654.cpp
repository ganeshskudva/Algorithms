/**
 * 654. Maximum Binary Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* head = nullptr;
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        recursive_choose_biggest(nums,left,right,&head,true);
        return head;
    }
    
    void recursive_choose_biggest(vector<int>& nums,int begin,int end,TreeNode** parent,bool is_left){
        if(begin > end)
            return;
        int max = -pow(2,31);
        int i = begin;
        int max_index = begin;
        for(;i <= end;i++){
            if(nums[i] > max){
                max_index = i;
                max = nums[i];
            }
        }

        TreeNode* node = new TreeNode(max);
        if(nullptr == *parent)
            *parent = node;
        else{
            if(is_left)
                (*parent)->left = node;
            else
                (*parent)->right = node;
        }
        recursive_choose_biggest(nums,begin,max_index-1,&node,true);
        recursive_choose_biggest(nums,max_index+1,end,&node,false);
    }
};
