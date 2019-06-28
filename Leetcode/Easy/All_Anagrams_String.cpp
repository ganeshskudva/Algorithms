// 438. Find All Anagrams in a String
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> table;
        vector<int> ans;
        
        for(char c : p){
            table[c]++;
        }
        
        if(s.length() < p.length() || s.length() == 0) return ans;
        
        int begin = 0, end = 0, word_size = p.length();
        int counter = table.size();
        
        while(end  < s.length()){
            char endchar = s[end];
            
            if(table.count(endchar) == 1){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            
            while(counter == 0){
                if(end - begin == word_size) {
                    ans.push_back(begin);
                }
                
                char beginchar = s[begin];
                
                if(table.count(beginchar) == 1){
                    table[beginchar]++;
                    if(table[beginchar] > 0) counter++;
                }
                
                begin++;
            }
        }
        
        return ans;
        
    }
};
