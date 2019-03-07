/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/jewels-and-stones/submissions/
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewel;
        int cnt = 0, i;
        
        for (i = 0; i < J.size(); i++)
            jewel.insert(J[i]);
        
        for (i = 0; i < S.size(); i++) {
            if (jewel.count(S[i]) != 0)
                cnt++;
        }
            
    
        return cnt;
    }
};
