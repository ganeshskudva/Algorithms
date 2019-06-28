// 733. Flood Fill
class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        floodFillUtil(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    
    void floodFillUtil(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if(sr<0 || sr >= image.size())
            return;
        if(sc<0 || sc >= image[sr].size())
            return;
        if(image[sr][sc] != oldColor || image[sr][sc]==newColor)
            return;
        
        image[sr][sc]=newColor;
        floodFillUtil(image,sr+1,sc,oldColor,newColor);
        floodFillUtil(image,sr-1,sc,oldColor,newColor);
        floodFillUtil(image,sr,sc+1,oldColor,newColor);
        floodFillUtil(image,sr,sc-1,oldColor,newColor);
    }
};
