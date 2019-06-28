// 463. Island Perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0; 
  
        int C = grid[0].size();
        int R = grid.size();
        // Traversing the matrix and finding ones to 
        // calculate their contribution. 
        for (int i = 0; i < R; i++) 
            for (int j = 0; j < C; j++) 
                if (grid[i][j]) 
                    perimeter += (4 - numofneighbour(grid, i ,j, R, C)); 

        return perimeter; 
    }
    
    int numofneighbour(vector<vector<int>>& grid, int i, int j, int R, int C) 
    { 
        int count = 0; 

        // UP 
        if (i > 0 && grid[i - 1][j]) 
            count++; 

        // LEFT 
        if (j > 0 && grid[i][j - 1]) 
            count++; 

        // DOWN 
        if (i < R-1 && grid[i + 1][j]) 
            count++; 

        // RIGHT 
        if (j < C-1 && grid[i][j + 1]) 
            count++; 

        return count; 
    } 
};
