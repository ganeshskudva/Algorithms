// 30. Substring with Concatenation of All Words
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> table;
        vector<int> ans;
        
        if(words.size() == 0) return ans;
        
        int window_size = 0;
        int word_size = words[0].length();
        
        // building frequency table
        for(string word : words){
            window_size += word.length();
            table[word]++;
        }
        
        unordered_map<string, int> reference(table);
        
        int begin = 0, end = 0, counter = table.size();
        vector<string> tokens;
        
        if(s.length() < window_size) return ans;
        
        // we increment begin and end only in word_size 
        // there are only word_size possible start points for our window. 
        // end is actually the start of the last word in window or put in other words
        // the real end of window is actually at end + word_size
        for(int i = 0; i < word_size; i++){
            begin = i; end = i;
            table = reference; // reset to original frequency table after every iteration
            counter = table.size();
            
            while(end + word_size -1 < s.length()){
                string lastword = s.substr(end, word_size);
                
                if(table.count(lastword) == 1){
                    table[lastword]--;
                    if(table[lastword] == 0) counter--;
                }

                if(end + word_size - begin == window_size){
                    // counter == 0, valid answer !
                    if(counter == 0){
                        ans.push_back(begin);
                    } 

                    string firstword = s.substr(begin, word_size);
                    
                    if(table.count(firstword) == 1){
                        table[firstword]++;
                        if(table[firstword] > 0) counter++;
                    }

                    begin += word_size;
                }

                end += word_size;
            }
        }
        
        return ans;
    }
};
