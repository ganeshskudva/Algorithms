// 509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        
        vector<int> f;
        f.push_back(0);
        f.push_back(1);
        
        if (n == 1)
            return 1;
        
        if (n == 2)
            return 1;
        
        for(int i=2;i<=n;i++){
            f.push_back(f[i-1]+f[i-2]);
        }
        return f[n];
        
    }
};
