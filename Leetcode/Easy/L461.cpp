// 461. Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^y;
        int cnt = 0;
        
        while (z) {
            z &= (z-1);
            cnt++;
        }
        
        return cnt;
    }
};
