// 7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int ret = 0;
        bool flag = x < 0;
        x = flag ? -x : x;
        while(x > 0) {
            if(INT_MAX / 10 < ret) return 0;
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        return flag ? -ret : ret;
    }
};
