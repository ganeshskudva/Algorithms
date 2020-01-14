class Solution {
public:
 bool isPossible(vector<int>& nums) {
        unordered_map<int, int> dict, temp;
        for (auto& ele: nums) dict[ele]++;
        for (auto& ele: nums){
            if (dict[ele]==0)   //if the ele is already used in some sequence
                continue;
            else if (temp[ele]>0){  //if the ele can be added in the last consecutive sequence
                dict[ele]--;
                temp[ele]--;
                temp[ele+1]++;
                
            }else if (dict[ele+1]>0 && dict[ele+2]>0){ //this ele should form a consecutive sequence by itself since it cannot be appended to a previous sequence
                dict[ele]--;
                dict[ele+1]--;
                dict[ele+2]--;
                temp[ele+3]++;
            }else //doesn't belong to any consecutive sequence
                return false;
        }
        return true;
    }
};
