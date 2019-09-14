// 811. Subdomain Visit Count
class Solution {
public:
vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        vector<string> res;
        for (string c: cpdomains){
            int space = c.find_first_of(' ');
            int pos1 = c.find_first_of('.');
            int pos2 = c.find_last_of('.');
            int num = stoi(c.substr(0, space));
            string lowest = c.substr(space + 1);
            if (pos1 == pos2) {
                string top = c.substr(pos1 + 1);
                m[top]+=num;
            }
            else if (pos1 != pos2){
                string top = c.substr(pos2 + 1);
                string next = c.substr(pos1 + 1);
                m[top]+=num;
                m[next]+=num;
            }
            m[lowest]+=num;
        }
        
        for (auto c: m){
            res.push_back(to_string(c.second) + " " + c.first);
        }
        return res;

    }
};
