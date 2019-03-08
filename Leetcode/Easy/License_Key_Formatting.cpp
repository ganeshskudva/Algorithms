/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/license-key-formatting/
*/


class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int i = 0,j=0, cnt = 0, grp = 0, rem;
        string ret;
        
        for (i = 0; i < S.size(); i++) {
            if (S[i] != '-') {
                cnt++;
            }
        }
        
        grp = cnt/K;
        rem = cnt%K;
        if (rem != 0) {
            while (rem--) {
                if (S[j] != '-') {
                    ret += toUpper(S[j]);
                } else {
                    rem += 1;
                }
                j++;
            }
            if (grp)
                ret += '-';
        } 
        
            while (grp--) {
                
                for (i = 0; i < K; i++) {
                if (S[j] != '-') {
                    ret += toUpper(S[j]);
                }else {
                    i -= 1;
                }
                    j++;
                }
                
                if (grp)
                    ret += '-';
                
            }
        
        return ret;
        
    }
    
    char toUpper(char ch) {
        
        if (ch >= '0' && ch <= '9') {
            return ch;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return ch;
        }
        
        ch = ch - 'a';
        ch = ch + 'A';
        
        return ch;
    }
};
