// 766. Toeplitz Matrix
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
       if(matrix.size()==1) return true;
      
        int sizeOfScores=matrix[0].size(); 
      
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<sizeOfScores-1;j++){
                if( matrix[i-1][j]!= matrix[i][j+1] ) return false;
            }
        }
    
        return true;
    }
};
