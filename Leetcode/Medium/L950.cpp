// 950. Reveal Cards In Increasing Order
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> seq;
        for (int i = 0; i < deck.size(); i++) seq.push(i);
        vector<int> order;
        while (!seq.empty()) {
            order.push_back(seq.front());
            seq.pop();
            if (!seq.empty()) { seq.push(seq.front()); seq.pop(); }
        }
        vector<int> ret(deck.size(), 0);
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); i++)
            ret[order[i]] = deck[i];
        return ret;
    }
};
