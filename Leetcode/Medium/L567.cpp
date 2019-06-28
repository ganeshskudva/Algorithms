// 567. Permutation in String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> table;
        
        for(char c : s1){
            table[c]++;
        }
        
        int begin = 0, end = 0, counter = table.size();
        
        while(end < s2.length()){
            char endchar = s2[end];
            
            if(table.count(endchar) == 1){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            
            while(counter == 0){
                if(end - begin == s1.length()) return true;
                
                char startchar = s2[begin];
                
                if(table.count(startchar) == 1){
                    table[startchar]++;
                    if(table[startchar] > 0) counter++;
                }
                
                begin++;
            }
        }
        
        return false;
    }
};
