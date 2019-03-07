/*
* AUTHOR: Ganesh S Kudva
* https://leetcode.com/problems/unique-email-addresses/submissions/
*/


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        size_t size = emails.size();
        int i = 0;
        string email, val;
        set<string> mail;
        bool ignore = false, alphaSeen = false;
        
        for (int j = 0; j < size; j++) {
            ignore = false;
            alphaSeen = false;
            email.clear();
            val = emails[j];
            for (int i = 0; i < val.size(); i++) {
                if (val[i] == '.' && !alphaSeen) {
                    continue;
                } else if (val[i] == '+' && !alphaSeen) {
                    ignore = true;
                    continue;
                } else if (val[i] == '@') {
                    ignore = false;
                    email += val[i];
                    alphaSeen = true;
                } else if (ignore) { 
                    continue;  
                } else {
                    email += val[i];
                }
            }
            mail.insert(email);
        }
        
        return mail.size();
    }
};
