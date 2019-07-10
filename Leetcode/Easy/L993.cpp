// 993. Cousins in Binary Tree
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        std::unordered_map<int, pair<int, TreeNode*>> hashMap;  //(val, (depth, parent))
        std::queue<TreeNode*> queue;
        int depth = 1;
        
        queue.push(root);
        
        while(!queue.empty()){
            int size = queue.size();
            
            for(int i=0; i<size; i++){
                TreeNode* node = queue.front();
                queue.pop();
                
                if(node->left){
                    queue.push(node->left);
                    if(node->left->val==x){
                        hashMap.insert(std::make_pair(x, std::make_pair(depth, node)));
                    }
                    if(node->left->val==y){
                        hashMap.insert(std::make_pair(y, std::make_pair(depth, node)));
                    }
                }
            
                if(node->right){
                    queue.push(node->right);
                    if(node->right->val==x){
                        hashMap.insert(std::make_pair(x, std::make_pair(depth, node)));
                    }
                    if(node->right->val==y){
                        hashMap.insert(std::make_pair(y, std::make_pair(depth, node)));
                    }
                }
            }
            depth++;
        }
        
        std::unordered_map<int, pair<int, TreeNode*>>::iterator it_x;
        std::unordered_map<int, pair<int, TreeNode*>>::iterator it_y;
        
        it_x = hashMap.find(x);
        it_y = hashMap.find(y);
        
        if(it_x==hashMap.end()) return false;   //if x not found
        if(it_y==hashMap.end()) return false;   //if y not found

        return it_x->second.first==it_y->second.first && it_x->second.second!=it_y->second.second;
    }
};
