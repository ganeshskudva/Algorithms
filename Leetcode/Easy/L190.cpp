// 190. Reverse Bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t temp = 0;
        uint32_t reverse=0;
        for(uint32_t i =32;i>0;i--)
        {
            temp = (n >> i-1)&1;
            
            reverse |= temp<<(32-i);
            
        }
        return reverse;
    }
};
