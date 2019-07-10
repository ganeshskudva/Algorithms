// 954. Array of Doubled Pairs
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < A.size(); i++){
            map[A[i]]++;
        }
        sort(A.begin(), A.end());
        unordered_map<int, int>::iterator itr;
        for(int i = 0; i < A.size(); i++){
            if(map[A[i]] == 0) continue;
            if(A[i] < 0){
			    //If -ve value, we need to find A[i]/2
                itr = map.find(A[i]/2);
            }else{
			    //If +ve, simply find 2*A[i]
                itr = map.find(2*A[i]);
            }
            
            if(itr == map.end()){
			    //Entry not found
                return false;
            }else if(itr->second == 0){
                //Entry present but used
                return false;
            }else{
                itr->second--;
            }
            map[A[i]]--;
        }
        
        return true;
    }
};
