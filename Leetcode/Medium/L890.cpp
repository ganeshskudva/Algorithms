class Solution {
public:
    bool matchesPattern(const string& word, const string& pattern)
    {
        unordered_map<char, char> patterncharToWordchar;
        unordered_map<char, char> wordcharToPatternchar;
        for (int i = 0; i < word.length(); ++i)
        {
            char patternChar = pattern[i];
            char wordChar = word[i];

            if (patterncharToWordchar.count(patternChar))
                if (patterncharToWordchar[patternChar] != wordChar)
                    return false;				
            if (wordcharToPatternchar.count(wordChar))
                if (wordcharToPatternchar[wordChar] != patternChar)
                    return false;

            patterncharToWordchar[patternChar] = wordChar;
            wordcharToPatternchar[wordChar] = patternChar;
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer;        
        for (string w : words)
            if (matchesPattern(w, pattern))
                answer.push_back(w);
        return answer;        
    }
};
