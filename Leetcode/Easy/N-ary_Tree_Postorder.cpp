/*
// 590. N-ary Tree Postorder Traversal
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        unordered_map<Node*,int> id;
        vector<int> res;
        if(root==NULL) return res;
        s.push(root);
        while(!s.empty()){
            auto p=s.top();
            if(id[p]<p->children.size()){
                s.push((p->children)[id[p]]);
                id[p]++;
            }else{
                res.push_back(p->val);
                s.pop();
            }                        
        }
        return res;
    }
};
