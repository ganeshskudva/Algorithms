// 559. Maximum Depth of N-ary Tree
class Solution {
private:
    int bfs(Node* root, int ans){
        list<pair<Node*, int> > q; //queue
        q.push_back(make_pair(root, 1));
        while(!q.empty()){
            Node* node = q.front().first;
            int depth = q.front().second;
            q.pop_front();
            for(Node* child: node->children){
                q.push_back(make_pair(child, depth+1));
				// keeps track of which node is at which depth
                ans = max(ans, depth+1);
            }
        }
        return ans;
    }
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        if(root->children.size() == 0) return 1;
        int ans = bfs(root, 0);
        return ans;
    }
};
