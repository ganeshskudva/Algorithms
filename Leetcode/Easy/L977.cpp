// 977. Squares of a Sorted Array
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        map<int, int> sq;
        vector<int> vec;
        
        for (int i = 0; i < A.size(); i++)
            sq[A[i]*A[i]]++;
        
        for (auto it = sq.begin(); it != sq.end(); ++it) {
            if (it->second == 1)
                vec.push_back(it->first);
            else {
                for (int j = 0; j < it->second; j++)
                    vec.push_back(it->first);
            }
        }
           
        
        return vec;
    }
};
