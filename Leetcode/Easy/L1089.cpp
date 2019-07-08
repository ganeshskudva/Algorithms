// 1089. Duplicate Zeros
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> vec;
        
        for (int i = 0; i < arr.size(); i++) {
            vec.push_back(arr[i]);
            if (arr[i] == 0 && vec.size()+1 <= arr.size()) {
                vec.push_back(0);
            }
            
            if (vec.size() == arr.size() )
                break;
        }
        
        arr = vec;
    }
};
