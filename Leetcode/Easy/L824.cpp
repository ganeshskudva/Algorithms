// 824. Goat Latin
class Solution {
public:
string toGoatLatin(string S) {
        
        int front = 0;
        int count = 1;
        int n = S.size();
        string res;
        
        for(int i=0; i<=n; i++)
        {
            if(i == n || S[i] == ' ')
            {
                string word(S.begin() + front, S.begin() + i);
                
                if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e' || word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'o' || word[0] == 'O' || word[0] == 'u' || word[0] == 'U')
                    res += word + "ma";
                else
                    res += word.substr(1) + word[0] + "ma";
                
                for(int k=0; k<count; k++)
                    res += 'a';
                
                if(i != n)
                    res += " ";
                front = i+1;
                count++;
            }
        }
        
        return res;
    }
};
