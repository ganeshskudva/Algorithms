// Remove All Adjacent Duplicates in String II
class Solution {
public:
string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack = {{0, '#'}};
        for (char c: s) {
            if (stack.back().second != c) {
                stack.push_back({1, c});
            } else if (++stack.back().first == k)
                stack.pop_back();
        }
        string res;
        for (auto & p : stack) {
            res += string(p.first, p.second);
        }
        return res;
    }
};
