// 914. X of a Kind in a Deck of Cards
class Solution {
    public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int count = 0;
        unordered_map<int, int> mmp;
        for(auto &x : deck) ++mmp[x];
        int bound = mmp.begin()->second;
        if(bound < 2) return false;
        for(int x = 2; x <= bound; ++x){
            for(auto &m : mmp)
                if(m.second % x == 0) ++count;
            if(count == mmp.size()) return true;
            else
                count = 0;
        }
        return false;
    }
};
