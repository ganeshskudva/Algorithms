class Solution {
public:
bool isNStraightHand(vector<int> &hand, int W)
{
    map<int, int> count;
    int size = hand.size(), i, val, cnt, k, value;
    bool impossible = false;

    for (i = 0; i < size; i++) {
        count[hand[i]]++;
    }

    for (auto it = count.begin(); it != count.end(); ++it) {
        if (it->second != 0) {
            value = it->second; 
            for (k = 0; k < value; k++)
            {
                val = it->first + 1;
                cnt = W -1;
                impossible = false;
                count[it->first]--;
                while (cnt) {
                    if (count.find(val) == count.end())
                        impossible = true;
                    else if (count[val] == 0)
                        impossible = true;

                    if (impossible)
                        break;
                    
                    count[val]--;
                    cnt--;
                    val++;
                }
                if (impossible)
                    break;
            }
        }
        if (impossible)
            break;
    }

    return !impossible;
}
};
