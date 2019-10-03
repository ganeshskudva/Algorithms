// 1002. Find Common Characters
class Solution {
public:
    vector<string> commonChars(vector<string>& A) 
    {
		// Frequency of each char in each string.
        int freq[A.size()][26] = {0};
		
		// A list of common chars across all strings.
        vector<string> common;
        
        // Count the frequency of each char from each string.
        for (int idx = 0; idx < A.size(); ++idx)
        {
            for (auto ch : A[idx])
            {
                freq[idx][ch - 'a']++;
            }
        }
        
        for (char ch = 0; ch < 26; ++ch)
        {
			// Minimum frequency of current char. 100 comes from question assumption.
            int minFreq = 100;
			
            for (int idx = 0; idx < A.size(); ++idx)
            {
                if (minFreq > freq[idx][ch])
                {
                    minFreq = freq[idx][ch];
                }
            }
            
			// Append minFreq number of chars to the 'common' vector.
            for (int idx = 0; idx < minFreq; ++idx)
            {
                common.push_back(string(1, ch + 'a'));
            }
        }
        
        return common;
        
    }
};
