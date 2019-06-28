// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        
        int begin = 0, end = 0;
        int len = 0;
        
        string ans = "";
        
        while(end < s.length()){
            char current = s[end];
            
            if(seen.count(current) == 1 && seen[current] >= begin){
                begin = seen[current] + 1;
            }
            else{
                seen[current] = end;
                end++;            
            }
            
            if(end - begin > len){
                len = end - begin;
                ans = s.substr(begin, end - begin);
            }
        }
        
        return len;
    }
};
