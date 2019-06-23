// 200. Number of Islands
class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
        int ans = 0; // number of groups 
      
        // iterating through given grid to find a '1'
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++; // start a group and visit all members of this group using dfs
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int y, int x){
        // if out of bounds or at a cell with '0' or '*', simply stop and return | end the dfs
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] != '1') return;
        
        grid[y][x] = '*'; // destroying visited cells so they are not re-visited
        
        // recursive dfs on all neighbours
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
        dfs(grid, y, x + 1);
        dfs(grid, y, x - 1);
    }
};
