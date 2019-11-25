// 1268. Search Suggestions System
class Solution {
public:
vector<vector<string>> suggestedProducts(vector<string>& ps, string word) {
    sort(begin(ps), end(ps));
    vector<vector<string>> res(word.size());
    for (auto l = 1; l <= word.size(); ++l) {
        auto w = word.substr(0, l);
        auto it = lower_bound(begin(ps), end(ps), w);
        for (; it != end(ps) && it->substr(0, l) == w && res[l - 1].size() < 3; ++it)
            res[l - 1].push_back(*it);
    }
    return res;
}
};
