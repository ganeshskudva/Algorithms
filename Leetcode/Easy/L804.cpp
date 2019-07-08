// 804. Unique Morse Code Words
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& s) {
        set<string>st;
        string pre[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0; i<s.size(); i++){
            string ans;
            for(int j=0; j<s[i].length(); j++){
                ans+=pre[(int)s[i][j]-97];
            }
            st.insert(ans);
        }
        return st.size();
    }
};
