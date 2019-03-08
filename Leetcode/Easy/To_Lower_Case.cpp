/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/to-lower-case/submissions/
*/

class Solution {
public:
    string toLowerCase(string str) {
        string temp;
        char ch;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                temp  += (str[i] - 'A') + 'a';
            } else {
                temp += str[i];
            }
        }
        
        return temp;
    }
};
