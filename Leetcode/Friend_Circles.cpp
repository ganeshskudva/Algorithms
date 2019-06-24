// 547. Friend Circles
class Solution {
public:
    // M is the friend matrix provided | basic intuition: we need connected components in graph, which can be done by BFS / DFS.
    // why does this work ? because applying transitive property to this : a friend of b, b friend of c , c friend of d
    // a,b,c,d should fall into 1 friend circle, just imagine a,b,c,d to be nodes of graph and they are connected by an edge if they 
    // are friends else not connected by an edge, so simply finding the total groups / connected components gives us the answer. 
    int findCircleNum(vector<vector<int>>& M) {                                     
        vector<bool> friendZoned(M.size(), false);                                  // array to keep track of visited in DFS
        stack<int> dfs;                                                             // stack to execute DFS 
        
        int circles = 0;                                                            // final ans stored in circles
        
        for(int i = 0; i < M.size(); i++){
            if(!friendZoned[i]){                                                   
                circles++;  // // person i unvisited so start new friend circle
                
                // DFS magic : { push to stack - pop top - retrieve neighbours - repeat first 3 steps for each unvisited neighbour until stack empty } 
                dfs.push(i);
                
                while(!dfs.empty()){
                    int current = dfs.top(); dfs.pop(); // pop top 
                    friendZoned[current] = true;        // mark node visited
                    
                    // retrieve it's unvisited neighbours and push them to stack
                    for(int j = 0; j < M[current].size(); j++){
                        if(!friendZoned[j] && M[current][j] == 1){                                
                            dfs.push(j);
                        }
                    }
                }
            }
        }
        
        return circles;
    }
};
