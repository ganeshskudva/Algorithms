// 832. Flipping an Image
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        for(int i=0; i<n; i++){
            reverse(A[i].begin(), A[i].end());
            for(int j=0; j<m; j++){
                if(A[i][j]) A[i][j]=0;
                else A[i][j]=1;
            }
        }
        return A;
    }
};
