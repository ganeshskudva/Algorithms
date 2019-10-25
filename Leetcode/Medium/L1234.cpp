// 1234. Replace the Substring for Balanced String
class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> count;
        int n = s.length(), res = n, i = 0, k = n / 4;
        for (int j = 0; j < n; ++j) {
            count[s[j]]++;
        }
        for (int j = 0; j < n; ++j) {
            count[s[j]]--;
            while (i <= n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                res = min(res, j - i + 1);
                count[s[i++]] += 1;
            }
        }
        return res;
    }
};
