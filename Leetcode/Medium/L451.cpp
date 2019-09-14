// 451. Sort Characters By Frequency
class Solution {
  using pq_key = pair<char, int>;
  struct comparator {
    bool operator()(pq_key &lhs, pq_key &rhs) {
      return lhs.second < rhs.second;
    }
  };
 public:
  // Time complexity: O(N)
  // Memory complexity: O(1)
  string frequencySort(string s) {
    // compute freq: O(N), where N = s.size()
    unordered_map<char, int> mp;
    for (char ch : s)
      mp[ch]++;

    // construct priority_queue max: O(|mp|) = O(1), because |mp| = alphabet_size
    priority_queue<pq_key, vector<pq_key>, comparator> pq (begin(mp), end(mp));

    // construct result: O(N log|pq|) = O(N)
    s.clear(); //< doesn't change capacity
    while (!pq.empty()) {
      pq_key top = pq.top();
      pq.pop();
      while (top.second-- > 0)
        s.push_back(top.first);
    }
    return move(s);
  }
};
