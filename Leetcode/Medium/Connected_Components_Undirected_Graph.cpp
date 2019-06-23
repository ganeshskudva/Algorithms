//323. Number of Connected Components in an Undirected Graph
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n, vector<int>(0));
        stack<int> dfs;
        
        int count = 0;
        int ans = 0;
        
        // building the graph's adjacency list
        for(auto edge : edges){
            int from = edge.first; 
            int to   = edge.second;
            
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }
        
        // dfs on nodes to find connected components
        for(int i = 0; i < n; i++){  
            if(!visited[i]){
                ans++;
                dfs.push(i);
                
                while(!dfs.empty()){
                    int current = dfs.top(); dfs.pop();
                    visited[current] = true;
                    
                    for(int neighbour : adjList[current]){
                        if(!visited[neighbour]) dfs.push(neighbour);
                    }
                }
            }             
        }
        
        return ans;
    }
};
