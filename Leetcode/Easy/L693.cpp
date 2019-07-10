//693. Binary Number with Alternating Bits
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i = 0, val, prev = -1;
        
        while (n > 0) {
            val = n%2;
            n = n/2;
            
            if (prev == -1)
                prev = val;
            else {
                if (prev == val)
                    return false;
                prev = val;
            }
        }
        
        return true;
    }
};
