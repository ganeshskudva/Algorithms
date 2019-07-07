/*
* 1104. Path In Zigzag Labelled Binary Tree
* don't start from first level to find the correct label on the path.
* we should start from the end level.

* every two adjacent levels has one swapped.
* we need to keep the last level for the correct label.
*/
class Solution {
public:
vector<int> pathInZigZagTree(int label)
    {
        // take root as level 0
        // then every level starts from 2^k, ends at 2^(k+1) - 1
		// so if we need to swap label x, we just do: 2^k + 2^(k+1)-1 -x = 3 * 2^k - 1 - x 
		
		// and for level n
		// first label is 1<<n

        std::vector<int> res;
        for(int k = label; k; k /= 2){
            res.push_back(k);
        }

        for(int i = 0; i < res.size(); ++i){
            if(i % 2){
                int exp = 1 << (res.size() - 1 - i);
                int sum = 3 * exp - 1;
                res[i] = sum - res[i];
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
