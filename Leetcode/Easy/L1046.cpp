// 1046. Last Stone Weight
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
    int x, y;

    for (int i = 0; i < stones.size(); i++)
    {
        pq.push(stones[i]);
    }

    x = -1;
    y = -1;
    while (!pq.empty())
    {
        if (y == -1)
        {
            y = pq.top();
        }
        else
        {
            x = pq.top();
        }
        pq.pop();

        if (x != -1 && y != -1)
        {
            if (x != y)
            {
                pq.push(y - x);
            }
            x = -1;
            y = -1;
        }
    }

    if (pq.empty()) {
        if (x == -1 && y == -1) {
            return 0;
        } else 
        {
            return y;
        }
    } else {
        return pq.top();
    }
    }
};
